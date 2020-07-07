/**
 * 题解：加油站
 * 目标：寻找一点i到length-1可到达（i...length-1每两点之间和为正） 
 * 反证法
**/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int total_tank = 0;      //总油量剩余值
    	int curr_tank = 0;       //	101从i到j两站之间油量剩余值
    	int start = 0; //初始站
    	int length = gas.size();

    	for (int i = 0; i < length; ++i)
    	{
    		total_tank += gas[i] - cost[i];
    		curr_tank += gas[i] - cost[i];
    		if (cur_tank < 0)   // i不可成为出发点  
    		{
    			start = i+1;
    			curr_tank = 0;
    		}
    	}
    	return total_tank < 0 ? -1 : start;
    }
};