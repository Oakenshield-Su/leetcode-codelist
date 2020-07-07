// 结果超时
class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int length = nums.size();
        if (length == 0)
        	return false;
        vector<bool> dp(length, false);    //dp[i]：位置i是否可达

        dp[0] = true;    //初始情况
        for (int i = 0; i < length; ++i)   //循环遍历dp数组
        {
        	if (dp[i])         //只有在dp[i]可达的情况下可以往后转移状态
        	{
        		for (int j = i+1; j <= i+nums[i] && j < length; ++j)        //从左向右遍历
        			dp[j] = true;
        	}
        	if (dp[length-1]) break;
        }
        return dp[length-1];
    }
};