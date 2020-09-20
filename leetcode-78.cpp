/**
 * 题解78：子集
 * 思路1：回溯+剪枝（剪枝条件：元素递增才可访问）
 * 递增式循环无需visited数组
**/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();
        dfs(nums, 0, n-1, path, ans);
        return ans;
    }

    void dfs(vector<int>& nums, int left, int right, vector<int>& path, vector<vector<int>>& ans){
    	ans.push_back(path);
    	//回溯逻辑
    	for (int i = left; i <= right; ++i)
    	{
    		path.push_back(nums[i]);  //加入搜索空间
    		dfs(nums, i+1, right, path, ans);
    		path.pop_back();	      //退出搜索空间
    	}
    }
};