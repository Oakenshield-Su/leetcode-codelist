/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 题解：翻转二叉树
 * 思路：后序遍历二叉树，每个节点都进行左右节点互换，最后整棵树将翻转
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    	if (root)
    	{
    		invertTree(root->left);
    		invertTree(root->right);
    		//左右节点互换
    		childNodeSwap(root);
    	}
    	return root;
    }


    void childNodeSwap(TreeNode &root){
    	TreeNode *temp = root->left;
    	root->left = root->right;
    	root->right = temp;
    }
};