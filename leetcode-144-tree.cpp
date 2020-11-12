/**
 * 二叉树前序遍历-非递归版
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;   //栈保存上次根节点，以便访问完左子树后可以访问右子树
        TreeNode* p = root;

        while(!s.empty() || p){
            if(p){
                res.push_back(p->val);
                s.push(p);
                p = p->left;   //向左子树遍历
            }else {
                p = s.top();   //左子树访问完后使用根节点来访问右子树
                s.pop();
                p = p->right;  //向右子树遍历                     
            }
        }

        return res;
    }

};