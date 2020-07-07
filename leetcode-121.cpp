class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int size = prices.size();
    	if (size <= 1)    //边界条件，例如：当天买入当天卖出
    		return 0;
    	int profits[size];
    	for (int i = 1; i < size; ++i)
    		profits[i] = prices[i] - prices[i-1];        //计算每天的利润差

    	int currentProfit = 0;  //当前利润和
    	int maxProfit = 0;      //最大利润和
    	//状态方程：max(n) = max(n-1) + p(n) 且 p(n) => 0 
    	for (int i = 1; i < size; ++i)
    	{
    		currentProfit += profits[i];
    		if (currentProfit < 0)    //当前利润和不小于0，说明后面仍有机会
    			currentProfit = 0;
    		if (currentProfit > maxProfit)
    			maxProfit = currentProfit;
    	}
    	return maxProfit;
    }
}; 
