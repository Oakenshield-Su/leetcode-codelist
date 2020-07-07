/**
 * 题解：最大正方形
**/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    	if (matrix.empty() || matrix[0].empty())
            return 0;
    	int n = matrix.size();
        int m = matrix[0].size();
    	vector<vector<int>> dp(n, vector<int>(m, 0));
		int res = 0;
    	for (int i = 0; i < m; ++i)
    	{
    		if (matrix[0][i] == '1'){
    			dp[0][i] = 1;
    			res = 1;
    		}
    	}

    	for (int i = 0; i < n; ++i)
    	{
    		if (matrix[i][0] == '1'){
    			dp[i][0] = 1;
    			res = 1;
    		}
    	}

    	for (int i = 1; i < n; ++i)
    	{
    		for (int j = 1; j < m; ++j)
    		{
    			if (matrix[i][j] == '1')
    			{
    				dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
    				res = max(res, dp[i][j]);
    			}
    		}
    	}
    	return res*res;
    }
};