/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 题解：二叉树中序遍历（非递归版本）
 * 
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> trace;
        stack<TreeNode *> nodeStack;
        TreeNode *cur = root;

        while(cur != nullptr || !nodeStack.isEmpty()){
        	if (cur != nullptr)
        	{
        		nodeStack.push(cur);
        		cur = cur->left;
        	}else{
        		cur = nodeStack.top();
        		trace.push_back(cur);
        		nodeStack.pop();
        		cur = cur->right;
        	}
        }
        return trace;
    }


};