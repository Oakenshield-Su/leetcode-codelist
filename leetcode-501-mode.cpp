/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 题解：二叉搜索树中的众数
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
    	vector<int> ans;
    	if (root == nullptr) //边界条件 
    		return ans;
    	TreeNode* pre = nullptr;
    	int curCount = 1, maxCount = 0;    //非空情况下curCount >= 1
    	inOrder(root, pre, curCount, maxCount, ans);
        return ans;
    }

    void inOrder(TreeNode* root, TreeNode* &pre, int& curCount, int& maxCount, vector<int>& ans){
    	if (root)
    	{
    		inOrder(root->left, pre, curCount, maxCount, ans);
    		if (pre)      //初始情况pre为空
    			curCount = (root->val == pre->val) ? curCount + 1 : 1; //如果前驱与当前相等则count增一，否则复位重新开始统计
    		if (curCount == maxCount)         //如果curCount == maxCount说明当前数字也是诸多众数中的一个
    		{
    			ans.push_back(root->val);
    		}else if(curCount > maxCount){   //如果curCount > maxCount说明当前数字为新的众数，前面的众数都失效
    			ans.clear();
    			ans.push_back(root->val);
    			maxCount = curCount;
    		}
    		pre = root;                //记录前驱
    		inOrder(root->right, pre, curCount, maxCount, ans);
    	}
    }
};