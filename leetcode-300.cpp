/**
 * 最长上升子序列长
 * 
**/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	int length = nums.size();
    	if (length == 0)  //边界条件
    		return 0;
    	vector<int> dp(length, 0);
    	int maxLength = 0;
    	for (int i = 0; i < length; ++i)
    	{
    		dp[i] = 1;      //每个子问题初始均为1即nums[i]为长度为1的子序列
    		for (int j = 0; j < i; ++j)
    		{
    			if (nums[j] < nums[i])
    			{
    				dp[i] = max(dp[i], dp[j]+1);        //从nums[0, i-1]中所有符合nums[j] < nums[i]条件的子问题中挑选最大子问题转移
    			}
    		}
    		maxLength = max(dp[i], maxLength);
    	}
    	return maxLength;
    }
};