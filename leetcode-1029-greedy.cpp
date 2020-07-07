/**
 * 题解：两地调度
 * 描述：公司计划面试 2N 人。第 i 人飞往 A 市的费用为 costs[i][0]，飞往 B 市的费用为 costs[i][1]。
	     返回将每个人都飞到某座城市的最低费用，要求每个城市都有 N 人抵达。
 * 思想：每个人都必须去一个城市那么选择城市时一定选择越便宜的越好,但是放入2N这个整体当中一定是选择便宜的越多越好
         比如：A:[60, 10] 跟 B:[300, 250]无论如何选择都是310
               A:[60, 10] 跟 B:[300, 260],A去两地的费用相差比B多,所以挑选A中便宜的那个
**/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
    	int size = costs.size();
    	int res = 0;

    	vector<int> diff(size);
    	for (int i = 0; i < size; ++i)
    		diff[i] = cost[i][0] - cost[i][1];    //计算两地调度费用差值
    	sort(diff.begin(), diff.end());       //针对便宜程度排序

    	for (int i = 0; i < size; ++i)
    	{
    		res += cost[i][1];
    		..............................................................................................................................+
    		
    		if (i < size/2)               
    			res += diff[i];         //选择相对最便宜的去另一个城市 
    	}
    	return res;
    }
};