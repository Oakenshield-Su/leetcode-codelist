/**
 * 题解：计算各个位数不同的数字个数
 * 难点：状态数组难以定义
**/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
    	if (n == 0)
    		return 1;
    	if (n == 1)
    		return 10;

    	vector<int> dp(n+1, 0);
    	dp[0] = 1;
    	dp[1] = 9;        //注意此时以dp[2]内的数字为数字首字母进行动态规划所以不能计算0
    	int sum = 10;
    	for (int i = 2; i <= min(n, 10); ++i)        //n > 10时最后一位一定重复
    	{
    		dp[i] = dp[i-1] * ( 10 - (i - 1));       //前i-1位已经确定最后一位从10 - (i - 1)个数字中选取一个
    		sum += dp[i];
    	}
    	return sum;
    }
};