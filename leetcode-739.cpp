/**
 * 题解：每日温度（单调栈）
 * 目标：寻找温度更高的某天
 * 方法：维护一个单减栈
**/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
    	int t_size = T.size();
    	vector<int> res(t_size, 0);
    	
    	stack<int> s;      //单减序列的下标
    	for (int i = 0; i < t_size; ++i)
    	{
    		int top;
    		while(!s.empty() && T[top = s.top()] < T[i]){
    			res[top] = i - top;
    			s.pop();
    		}
    		s.push(i);
    	}
    	return res;
    }
};