/**
 * 题解：最后一块石头重量
 * 收获：优先队列始终保持有序 
 * C++默认大顶堆
 * priority_queue<int, vector<int>, less<int> > a 大顶堆
 * priority_queue<int, vector<int>, greater<int> > b  小顶堆
**/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        //构造大顶堆
        int last , pre, diff;
        priority_queue<int> s;
        for (int i = 0; i < n; ++i)
	        s.push(stones[i]);

	    while(s.size() > 1){
	    	last = s.top();       //获取最大元素
	    	s.pop();
	    	pre = s.top();        //获取次大元素
	    	s.pop();
	    	// diff = last > pre ? last - pre : pre - last; last一定大于pre
	    	diff = last - pre;
	    	if (diff > 0)
	    		s.push(diff);
	    }

	    return s.size() == 1 ? s.top() : 0;

    }
};