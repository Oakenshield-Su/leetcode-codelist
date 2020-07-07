/**
 * 最长回文子序列	
**/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
    	int size = s.size();
    	vector<vector<int>> dp(size,vector<int>(size, 0));
    	for (int i = 0; i < size; ++i)  //边界条件
    		dp[i][i] = 1;

    	for (int i = size-1; i >= 0; --i)      //倒序遍历
    	{
    		for (int j = i+1; j < size; ++j)
   			{
    			if (s[i] == s[j])
    			{
    				dp[i][j] = dp[i+1][j-1] + 2;   //s[i]和s[j]属于回文子序列的一部分
    			}else{
    				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
    			}
    		}
    	}

    	return dp[0][size-1];
    }
};