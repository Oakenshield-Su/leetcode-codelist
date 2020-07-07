/**
 * 题解：比特位计数
**/
class Solution {
public:
    vector<int> countBits(int num) {
    	vector<int> dp(num+1, 0);
    	dp[0] = 0;
    	for (int i = 1; i <= num; ++i)
    	{
    		if (i % 2 == 0)        //i为偶数时等价于i/2右移所以1的数量不变
    			dp[i] = dp[i/2];
    		else                   //i为奇数是暗含着i-1为偶数,又因为偶数的最低位为0所以最低位置为1即可
    			dp[i] = dp[i-1] + 1;
    	}
    	return dp;
    }
};