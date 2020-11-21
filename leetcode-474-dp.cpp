/**
 * 题解：474 一和零问题
 * 思路：类似0/1背包问题
**/

class Solution {
public:
	
    int findMaxForm(vector<string>& strs, int m, int n) {
		int size = strs.size();
    	vector<vector<vector<int>>> dp(size+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

    	int zeros = 0;
    	int ones = 0;
    	for (int k = 1; k <= size; ++k)    //k表示第k个字符串	
    	{
			ones = 0, zeros = 0;
    		for (int q = 0; q < strs[k-1].size() ; ++q)
    			strs[k-1][q] == '0' ? zeros++ : ones++;

    		//状态转移方程
    		for(int i = 0; i <= m; i++){
				for (int j = 0; j <= n; j++)
				{
					if (i >= zeros && j >= ones)
					{
						dp[k][i][j] = max(dp[k-1][i-zeros][j-ones] + 1, dp[k-1][i][j]);
					}else{
						dp[k][i][j] = dp[k-1][i][j];
					}
				}
			}
    	}
		return dp[size][m][n];
    }

	//经过分析第i个字符串的状态仅和i-1个字符串有关，所以可以将3维问题降维2维
	int findMaxForm(vector<string>& strs, int m, int n) {
		int size = strs.size();
    	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    	int zeros = 0;
    	int ones = 0;
    	for (int k = 1; k <= size; ++k)    //k表示第k个字符串	
    	{
			ones = 0, zeros = 0;
    		for (int q = 0; q < strs[k-1].size() ; ++q)
    			strs[k-1][q] == '0' ? zeros++ : ones++;

    		//状态转移方程
    		for(int i = m; i >= zeros; i--){
				for (int j = n; j >= ones; j--)
					dp[i][j] = max(dp[i-zeros][j-ones] + 1, dp[i][j]);
			}
    	}
		return dp[m][n];
    }
};