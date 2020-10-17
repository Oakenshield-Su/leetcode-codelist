/**
 * 题解：二叉树最近公共祖先
 * 思路：后序遍历+分叉点
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return root;
        if (root == q || root == p)    //路径结尾
        	return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);  //在root->left子树中是否能找到q或p
        TreeNode* right = lowestCommonAncestor(root->right, p, q); //在root->right子树中是否能找到q或p

        if (left != nullptr && right != nullptr)  //q p分别在同一棵以root为根的左右两棵子树
        	return root;
        // else if (left != nullptr && right == nullptr) //q p在同一棵以root为根的左子树
        // 	return left;
        // else if (right != nullptr && left == nullptr) //q p在同一棵以root为根的右子树
        // 	return right;
        // return nullptr;
        return (left == nullptr) ? right :left;
    }
};