class Solution {
public:
    int longestValidParentheses(string s) {
    	int length = s.length();
    	if (length == 0)
    		return 0;
        vector<int> dp(length, 0);
        int res = 0;
        for (int i = 1; i < length; ++i)
        {
        	if (s[i] == ')'){
        		if (s[i-1] == '('){
        			dp[i] = (i-2 >= 0 ? dp[i-2] : 0) + 2;
        		}else if (s[i-1] == ')'){
        			if (i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(')
        			{
        				dp[i] = (i-dp[i-1]-2 >= 0 ? dp[i-dp[i-1]-2] : 0) + dp[i-1] + 2; 
        			}
        		}
        	}
        	res = std::max(res, dp[i]);
        }
        return res;
    }
};