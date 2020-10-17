/**
 * 题解：二叉搜索树最近公共祖先
 * 思路：利用二叉搜索树的特性，寻找两个节点的分叉点
 * 当两个节点都大于或者都小于当前节点时，两个节点在同一子树
 * 否则当前节点为两个节点的分叉点
**/
class Solution {
public:
	//递归版
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (p->val < root->val && q->val < root->val) //同小在左子树
        	return lowestCommonAncestor(root->left, p, q);
        if (p->val > root->val && q->val > root->val) //同大在右子树
        	return lowestCommonAncestor(root->right, p, q);    
        return root;
    }

    //非递归版
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if (root == nullptr) return nullptr;
        TreeNode* ans = root;
    	while(true){
    		if (p->val < ans->val && q->val < ans->val)
    			ans = ans->left;
    		else if (p->val > ans->val && q->val > ans->val)
    			ans = ans->right;
    		else
    			break;
    	}
    	return ans;
    }
};