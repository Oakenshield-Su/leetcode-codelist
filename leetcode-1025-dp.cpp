class Solution {
public:
    bool divisorGame(int N) {
    	vector<bool> dp(N+1, false);
    	dp[1] = false;
    	dp[2] = true;

    	for (int i = 3; i <= N; ++i)
    	{
    		for (int j = 1; j < i; ++j)
    		{
    			if (i % j == 0 && !dp[i - j]){
	    			dp[i] = true;
	    			break;
	    		}
    		}
    	}

    	return dp[N];
    }
};