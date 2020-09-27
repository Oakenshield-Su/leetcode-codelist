/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 题解：路径总和
 * 思路：先序遍历+回溯剪枝
 * 回溯条件：
 * 1. sum == target加入结果集
 * 2. sum > target剪枝  （无法剪枝，因为target可正可负）
 * 3. sum < target搜索
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> path;
        backtracing(root, ans, path, sum);
        return ans;
    }

    void backtracing(TreeNode* root, vector<vector<int>> &ans, vector<int> &path, int sum){
    		if (root == nullptr) return;
            sum -= root->val;
            path.push_back(root->val);
    		if (sum == 0 && root->left == nullptr && root->right == nullptr)
    			ans.push_back(path);
    		backtracing(root->left, ans, path, sum);
    		backtracing(root->right, ans, path, sum);
    		path.pop_back();
    }
};