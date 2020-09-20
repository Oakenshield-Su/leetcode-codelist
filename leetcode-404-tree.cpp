/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 题解404：左叶子之和
 * 思路1：层次遍历，遍历到每个节点访问左孩子节点并判断是否为叶子节点
 * 思路2: 先序遍历
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
    	queue<TreeNode *> queue;
    	TreeNode *cur = root;
    	queue.push(root);
    	int ans = 0;
    	while(cur && !queue.empty()){
    		cur = queue.front();
    		if (cur->left != nullptr){
                queue.push(cur->left);
                if (!cur->left->left && !cur->left->right)         //判断左叶子
                    ans += cur->left->val;
            }
    		if (cur->right != nullptr)
    			queue.push(cur->right);
            
    		queue.pop();
    	}
    	return ans;
    }
};


/**
class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
        if(root == null) return 0;
        int res = 0;
        //判断节点是否是左叶子节点，如果是则将它的和累计起来
        if(root.left != null && root.left.left == null && root.left.right == null){
            res += root.left.val;
        }
        return sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right) + res;
    }
}
**/