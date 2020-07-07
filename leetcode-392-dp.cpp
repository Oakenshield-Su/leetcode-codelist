/**
 * 题解：判断子序列（动态规划）
 * 超时
**/
class Solution {
public:
    bool isSubsequence(string s, string t) {
    	int s_size = s.size();
		int t_size = t.size();
		if (s_size == 0)
			return true;
		if (t_size == 0)
			return false;
		vector<vector<bool>> dp(t_size+1, vector<bool>(s_size+1, false));
		for (int i = 0; i <= t_size; ++i)
			dp[i][0] = true;

		for (int i = 1; i <= t_size; ++i)
		{
			for (int j = 1; j <= s_size; ++j)
			{
				if (s[j-1] == t[i-1])
				{
					dp[i][j] = dp[i-1][j-1];
				}else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}

		return dp[t_size][s_size];
    }
};
