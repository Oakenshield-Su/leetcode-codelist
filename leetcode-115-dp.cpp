/**
 * 题解：不同的子序列
 * 描述：给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。
         一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。
         （例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
**/
class Solution {
public:
    int numDistinct(string s, string t) {
        int s_size = s.size();
        int t_size = t.size();

        vector<vector<long>> dp(s_size+1, vector<long>(t_size+1, 0));   //注意：中间过程可能很大使用long

        for (int i = 0; i <= s_size; ++i)        //边界条件：t为空串时s[0...i]皆包含t
        	dp[i][0] = 1;

        for (int i = 1; i <= s_size ; ++i)
        {
        	for (int j = 1; j <= t_size; ++j)
        	{
        		if (s[i-1] == t[j-1])
                    /**
                     * 当s[i-1] == t[j-1]相等时暗含两种状态转移
                     * 1.s的末尾与t的末尾匹配，此时只需看s[0:i-2]包含t[0:j-2]的子串个数
                     * 2.t的末尾与s[0:i-2]中的相同字符匹配，此时看s[0:i-2]包含t[0:j-1]的子串个数
                    **/
        			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];    
        		else 
        			dp[i][j] = dp[i-1][j];       //s[i-1]!=t[j-1]时查看s[0...i-2]中包含t[0...j-1]的数量
        	}
        }
        return dp[s_size][t_size];
    }
};