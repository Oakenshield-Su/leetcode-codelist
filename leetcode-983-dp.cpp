/**
 * 题解：最低票价
**/
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
    	int n = days.size();
    	int lastDay = days[n-1];

    	vector<int> dp(lastDay+1);
    	int index = 0;
    	for (int i = 1; i <= lastDay; ++i)
    	{
    	 	if (i == days[index]){  // i == dats[index] 说明这一天旅行则有三种买票方式
    	 		dp[i] = min(dp[max(0, i-1)] + costs[0], min(dp[max(0, i-7)] + costs[1], dp[max(0, i-30)] + costs[2]));
                index++;
    	 	}else{          // i != dats[index] 说明这一天没有旅行
     	 		dp[i] = dp[i-1];
    	 	}
    	} 
    	return dp[lastDay];
    }
};