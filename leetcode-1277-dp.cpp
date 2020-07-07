/**
 * 题解：正方形子矩形
 * 思路：类似于最大正方形，边长为n的正方形向外延伸n个子矩形
**/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	int m = matrix[0].size();      //n乘m矩形

    	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    	int res = 0;
    	for (int i = 1; i <= n; ++i)
    	{
    		for (int j = 1; j <= m; ++j)
    		{
    			if(matrix[i-1][j-1] == 1){
    				dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
    				res += dp[i][j];
    			}
    		}
    	}
    	return res;
    }
};