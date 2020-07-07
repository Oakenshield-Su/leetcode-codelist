/**
 * 题解：戳气球（类似：矩阵链乘）
**/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
    	nums.insert(nums.begin(), 1);    //首位填充
    	nums.push_back(1);	            //尾位填充
    	int n = nums.size();
    	vector<vector<int>> dp(n, vector<int>(n, 0));

    	for (int len = 2; len < n; ++len)
    		for (int l = 0, r = len; r < n; r++, l++)
    			for (int k = l+1; k < r; k++)
    				dp[l][r] = max(dp[l][r], dp[l][k]+dp[k][r]+nums[l]*nums[r]*nums[k]);
    	return dp[0][n-1];
    }
};