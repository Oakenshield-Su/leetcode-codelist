/**
 * 题解：无重叠区间（动态规划）
**/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    	sort(intervals.begin(), intervals.end(), compare);  // 区间起点降序排列

    	int size = intervals.size();
        if(size == 0) return 0;
    	vector<int> dp(size+1,1);
    	int maxOverlapIntervalsNum = 1;
    	for (int i = 1; i < size; ++i)
    	{
    		for (int j = 0; j < i; ++j)
    		{
    			if (intervals[j][1] <= intervals[i][0])     //无区间重叠
    			{
    				dp[i] = max(dp[i], dp[j]+1);
    			}
    		}
    		if (maxOverlapIntervalsNum < dp[i])
    		{
    			maxOverlapIntervalsNum = dp[i];
    		}
    	}
    	return size - maxOverlapIntervalsNum;
    }

    static bool compare(const vector<int> &a, const vector<int> &b){
    	if (a[0] < b[0])
    		return true;
    	return false;
    }
};