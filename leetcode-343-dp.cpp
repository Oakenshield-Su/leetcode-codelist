/**
 * 题解：整数拆分（动态规划）
**/
class Solution {
public:
    int integerBreak(int n) {
    	vector<int> dp(n+1, 0);
    	dp[1] = 1;    // 初始化

    	for (int i = 2; i <= n; ++i)
    	{
    		for (int j = 1; j < i; ++j)
    		{
    			dp[i] = max(dp[i], (i-j)*max(dp[j], j));     //注：j=2 j=3时dp[2]=1 dp[3]=2但是解子问题i=2，i=3是不拆分
    		}
    	}
    	return dp[n];
    }
};