/**
 * 116.填充每个节点的下一个右侧节点指针
 * 要求：常数级空间
 * 注：二叉树的根节点next始终为NULL
**/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)        //边界条件
        	return nullptr;
        if (root->left == nullptr)  //递归结束条件即递归到叶子节点（完美二叉树左节点为空的节点一定为叶子节点）
        	return root;

        root->left->next = root->right;  //根节点的左节点的next为该节点的右节点
        if (root->next)                  //防止空指针异常
         	root->right->next = root->next->left;    //根节点的右节点的next为根节点的next的左节点
        connect(root->left);
        connect(root->right);
        return root;
    }
};