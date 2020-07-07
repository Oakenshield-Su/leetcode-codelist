/**
 * 题解:股票问题含冷冻期
**/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int n = prices.size();
    	if (n < 2)
    		return 0;

    	vector<vector<int>> dp(n, vector<int>(3, 0));

    	dp[0][0] = 0;         //未持股
    	dp[0][1] = -1*prices[0];  //持股
    	dp[0][2] = 0;         //冷冻期

    	for (int i = 1; i < n; ++i)
    	{
    		dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
    		dp[i][1] = max(dp[i-1][1], dp[i-1][2] - prices[i]);
    		dp[i][2] = dp[i-1][0];
    	}

    	return max(dp[n-1][0], dp[n-1][2]);        //不比较dp[n-1][1]是因为当前持股未卖一定不是最大利润

    }
};