/**
 * 不同路径
**/
class Solution {
public:
    int uniquePaths(int m, int n) {
    	if (m == 0 || n == 0)
    		return 0;
        vector<vector<int>> dp(m,vector<int>(n));
        for (int i = 0; i < m; ++i)
        {
        	for (int j = 0; j < n; ++j)
        	{
        		if (i == 0 || j == 0)         //第一行第一列路径数为1
        		{
        			dp[i][j] = 1;
        		}else{						  //其余行列为上一行与上一列路径数相加
        			dp[i][j] = dp[i-1][j] + dp[i][j-1];      
        		}
        	}
        }
        return dp[m-1][n-1];
    }
};