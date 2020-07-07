/**
 * 题解：等和序列（背包问题）
**/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
    	int n = nums.size();
    	int sum = 0;
    	for (auto num: nums)
    		sum += num;
    	if (sum % 2 != 0)       //和为奇数
    		return false;
    	if (sum == 0)           //数组全为0
    		return true;      

    	int oneNumsSum = sum / 2;
    	vector<bool> dp(oneNumsSum+1 , false);
    	for (int i = 0; i <= oneNumsSum; ++i)         //未考虑初始化问题
    		dp[i] = (nums[0] == i);

    	for (int i = 1; i < n; ++i)
    	{
    		for (int j = oneNumsSum; j >= nums[i]; --j)
    		{
    			dp[j] = dp[j] || dp[j-nums[i]];
    		}
    	}

    	return dp[oneNumsSum];
    }
};