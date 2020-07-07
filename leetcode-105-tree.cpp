/**
 * 题解：前序和中序构造二叉树
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {								
        if (preorder.empty())
        	return NULL;
        int n = preorder.size();
        int start = 0;          //引用类型不使用临时变量如buildSubTree(preorder, inorder, 0, n-1, 0, n-1)
        TreeNode *root = buildSubTree(preorder, inorder, 0, n-1, start, n-1);
        return root;
    }

    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder,
    								 int start, int end, int &pre_left, int pre_right){
    	if (pre_left > pre_right || start > end)      //临界条件
    		return NULL;
    	TreeNode *root = new TreeNode(preorder[pre_left]);
    	int mid = findElem(inorder, start, end, preorder[pre_left++]);
    	root->left = buildSubTree(preorder, inorder, start, mid-1, pre_left, pre_right); //切勿++pre_left
    	root->right = buildSubTree(preorder, inorder, mid+1, end, pre_left, pre_right);
    	return root;
    }


    int findElem(vector<int>& inorder, int start, int end, int target){
    	for (int i = start; i <= end; ++i)
    	{
    		if (inorder[i] == target)
    			return i;
    	}
        return -1;
    }

    
};