/**
 * 题解：引爆气球
 * 贪心原则：排序后只要有区间的start小于当前区间的end,则符合条件的区间与当前区间一同引爆
**/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    	if (points.size() == 0)
    		return 0;
    	//排序
    	sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
    		return a[1] < b[1];
    	});

    	int arrows = 1;
    	int end = points[0][1];
    	for (auto point : points){
    		if (point[0] > end)      //point[0]为下一个气球的start
    		{
    			end = point[1];      //point[1]为下一个气球的end
    			arrows++;
    		}
    	}
    	return arrows;
    }
};