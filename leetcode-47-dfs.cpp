/*
 * 题解47：全排列2
 * 思路1：DFS+去重
 * 思路2：回溯+剪枝
 *    代码模板：
 *    	结束条件;
 *		循环遍历（枚举所有可能）:
 *			剪枝条件;
 *
 *			加入搜索树;
 *			DFS;
 *			回退;
 *		结束
 *
*/

class Solution {

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());      //数据集排序，便于去重
        vector<vector<int>> ans;
        dfs(nums, 0, nums.size()-1, ans);
        return ans;
    }

    void dfs(vector<int> nums, int left, int right, vector<vector<int>> &ans){
    	if (left == right)
    		ans.push_back(nums);
    	else{
    		for (int i = left; i < right; ++i)
    		{
    			if (i != left &&nums[left] == nums[i]) continue;     //去重
    			swap(nums[left], nums[i]);
    			dfs(nums, left+1, right, ans);
    		}
    	}
    }

    void dfs2(vector<int> &nums, int left, int right, vector<int> path, vector<bool> visited, vector<vector<int>> &ans){
    	if(left == right)
    		ans.push_back(path);

    	for (int i = 0; i <= right; ++i)
    	{
    		if (visited[i]) continue;
    		if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;    //剪枝操作

    		//加入节点
    		path.push_back(nums[i]);
    		visited[i] = true;

    		dfs(nums, left+1, right, path, visited, ans);      

    		//回退节点
    		visited[i] = false;
    		path.pop_back();
    	}
    }
};
