/**
 * 题解:打家劫舍
**/
class Solution {
public:
    int rob(vector<int>& nums) {
    	int n = nums.size();
        if (n == 0)
            return 0;

    	vector<int> dp(n+1);      //抢劫前K个房子获得的最大价值
    	dp[0] = 0;
    	dp[1] = nums[0];
    	for (int i = 2; i <= n; ++i)
    	{
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
    	}
    	return dp[n];
    }
};