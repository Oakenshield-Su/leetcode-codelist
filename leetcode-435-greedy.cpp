/**
 * 题解：无重叠区间（贪心算法）
 * 类似算法导论中活动选择问题
 * 定理：最小终点区间一定存在最大无重叠区间
**/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    	int size = intervals.size();
        if(size == 0) 
            return 0;

        sort(intervals.begin(), intervals.end(), compare);  // 区间终点降序排列
    	int maxOverlapIntervalsNum = 1;
        int index = 0;     //标记未加入最大无重叠区间的最小终点下标
        for (int i = 1; i < size; ++i)
        {
            if(intervals[index][1] <= intervals[i][0]){      //[..index]与[i...]不重叠
                maxOverlapIntervalsNum++;
                index = i;
            }
            // 省略部分：去除未加入最大无重叠区间的最小终点区间有交集的区间
        }
    	
    	return size - maxOverlapIntervalsNum;
    }

    static bool compare(const vector<int> &a, const vector<int> &b){
    	if (a[1] < b[1])
    		return true;
    	return false;
    }
};