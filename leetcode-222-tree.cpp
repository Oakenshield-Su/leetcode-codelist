#include <vector>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * 222.完全二叉树的节点个数
**/

class Solution
{
public:
    //暴力递归
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    //利用完全二叉树性质，定义left为左子树高度，right为右子树高度，如果left == right说明左子树为满二叉树，递归遍历右子树
    //如果left != right,说明右子树为满二叉树，递归遍历左子树
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left_deepth = countLevels(root->left);
        int right_deepth = countLevels(root->right);

        if (left_deepth == right_deepth)
        {
            return countNodes(root->right) + (1 << left_deepth);
        }
        else
        {
            return countNodes(root->left) + (1 << right_deepth);
        }
    }

    //统计完全二叉树的深度
    int countLevels(TreeNode *root)
    {
        int deepth = 0;
        TreeNode *cur = root;
        while (cur)
        {
            deepth++;
            cur = cur->left;
        }
        return deepth;
    }
};