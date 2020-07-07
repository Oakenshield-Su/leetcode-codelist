/**
 * 题解：摆动序列
**/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    	int size = nums.size();
    	if (size <2)
    		return size;
    	vector<vector<int>> dp(size, vector<int>(2));
    	dp[0][0] = 1;
    	dp[0][1] = 1;
    	for (int i = 1; i < size; ++i)
    	{
    		if (nums[i] > nums[i-1])
    		{
    			dp[i][0] = max(dp[i-1][1] + 1, dp[i-1][0]);
    		}else if (nums[i] < nums[i-1]){
    			dp[i][1] = max(dp[i-1][0]+1, dp[i-1][1]);
    		}else{
    			dp[i][0] = dp[i-1][0];
    			dp[i][1] = dp[i-1][1];
    		}
    	}
    	return max(dp[size-1][1], dp[size-1][0]);
    }
};