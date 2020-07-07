class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
    	int n = nums.size();
    	if (n == 0)
    		return 0;
    	vector<int> dp(n, 1);
    	vector<int> count(n, 1);


    	int maxLen = dp[0];
    	int res = 0;
    	for (int i = 1; i < n; ++i)
    	{
    		for (int j = 0; j < i; ++j)
    		{
    			if (nums[i] > nums[j]){
    				if (dp[j]+1 > dp[i]){//长度+1但是组合数不变
    					count[i] = count[j];
    					dp[i] = dp[j] + 1;
    				}     
    				else if (dp[j]+1 == dp[i])       //有新的组合
    					count[i] += count[j];
    			}
    				
    		}
    		maxLen = max(maxLen, dp[i]);
    	}

    	
    	for (int i = 0; i < n; ++i)
    	{
			if (maxLen == dp[i])
				res += count[i];
    	}

    	return res;
    }
};