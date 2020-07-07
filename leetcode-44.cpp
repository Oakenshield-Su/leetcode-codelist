class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.size();
        int p_len = p.size();

        //边界条件
        if (p.empty() && s.empty())
        	return true;

        vector<vector<bool>> dp(p_len+1, vector<bool>(s_len+1, false));
        dp[0][0] = true;
        //p为空时dp[0][i]全为false;
        //s为空时仅p[i]=="*"如"***"时dp[1][0]为true
        for (int i = 1; i <= p_len; ++i)
        	dp[i][0] = dp[i-1][0] && p[i-1] == '*';
        for (int i = 1; i <= p_len; ++i)
        {
        	for (int j = 1; j <= s_len; ++j)
        	{
        		if (p[i-1] == '*')
        		{
        			dp[i][j] = dp[i-1][j] || dp[i][j-1];
        		}else if(p[i-1] == '?' || p[i-1] == s[j-1]){ //当p[0...i-1]与s[0...j-1]匹配且p[i] == '?'或者p[i] == s[j]时匹配成功
        			dp[i][j] = dp[i-1][j-1];
        		}
        	}
        }

        return dp[p_len][s_len];
    }
};