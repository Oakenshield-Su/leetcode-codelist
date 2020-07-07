class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	int size = coins.size();
    	int max = amount + 1;   // f(amount)极限情况为全1
    	vector<int> dp(amount + 1, max);
    	dp[0] = 0;        // f(0) = 0
    	for (int i = 1; i <= amount; ++i)
    	{
    		for (int j = 0; j < size; ++j)
    		{
    			if (coins[j] <= i)
    			{
    				dp[i] = std::min(dp[i], dp[i-coins[j]] + 1);
    			}
    		}
    	}
    	return dp[amount] > amount ? -1 : dp[amount];        
    }
};