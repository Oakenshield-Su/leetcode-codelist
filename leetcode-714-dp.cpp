/**
 * 题解：股票问题（含手续费）
**/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
    	int n = prices.size();
    	vector<int> buy(n, 0);
    	vector<int> sell(n, 0);

    	buy[0] = -1*prices[0];
    	sell[0] = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		buy[i] = max(buy[i-1], sell[i-1] - prices[i]);
    		sell[i] = max(sell[i-1], buy[i-1] + prices[i] -fee);
    	}
    	return sell[n-1];
    }
};