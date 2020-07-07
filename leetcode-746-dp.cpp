/**
 * 题解：爬楼梯最小代价
**/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    	int n = cost.size();
    	vector<int> dp(n, 0);
    	dp[0] = cost[0];
    	dp[1] = cost[1];

    	for (int i = 2; i < n; ++i)
    		dp[i] = min(dp[i-1], dp[i-2]) + cost[i];

    	return min(dp[n-1], dp[n-2]);
    }


    //动态规划空间优化
    int minCostClimbingStairs(vector<int>& cost) {
    	int n = cost.size();
    	int pre = cost[0];
    	int cur = cost[1];
        int tmp;

    	for (int i = 2; i < n; ++i){
            tmp = cur;
    		cur = min(pre, cur) + cost[i];
            pre = tmp;
        }
    	return min(pre, cur);
    }
};