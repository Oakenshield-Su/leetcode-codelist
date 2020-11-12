/**
 * 题解：474 一和零问题
 * 思路：类似0/1背包问题
**/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
    	vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    	int size = strs.size();

    	dp[0][0] = 0;
    	int zeros = 0;
    	int ones = 0;
    	for (int i = 0; i < size; ++i)
    	{
    		for (int k = 0; i < strs[i].size() ; ++i)
    			strs[i][k] == 0 ? zeros++ : ones++;

    		//状态转移方程
    		
    	}
    }
};