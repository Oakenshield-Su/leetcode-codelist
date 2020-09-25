/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	unordered_map<int, int> index;
	int post_right;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	for (int i = 0; i < inorder.size(); ++i)   //构建后序遍历结果 值：索引的映射关系
    		index[inorder[i]] = i; 
    	post_right = (int)postorder.size() - 1;
        return process(inorder, postorder, 0, inorder.size() - 1);
    }

    TreeNode* process(vector<int>& inorder, vector<int>& postorder, int in_left, int in_right){
    	if (in_left > in_right)
    		return NULL;

    	int root_index = index[postorder[post_right]];      //根节点在中序遍历结果的位置

    	TreeNode* root = new TreeNode(inorder[root_index]);
    	post_right--;

    	//注意：后序遍历的特性，重构二叉树时先右后左
    	root->right = process(inorder, postorder,root_index + 1, in_right);
    	root->left = process(inorder, postorder, in_left, root_index - 1);
    	return root;
    }
};