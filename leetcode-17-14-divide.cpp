/**
 * 题解：最小K个数(小顶堆)
 * 思想：维护一个大小为K的小顶堆
**/
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
    	if (k == 0)
    		return {};
    	priority_queue<int> q;
    	vector<int> ans;
    	
    	for (int i = 0; i < k; ++i)
    		q.push(arr[i]);
    	for (int i = k; i < arr.size(); ++i)
    	{
    		if (arr[i] < q.top())
    		{
    			q.pop();
    			q.push(arr[i]);
    		}
    	}

    	while(!q.empty()){
    		ans.push_back(q.top());
    		q.pop();
    	}

    	return ans;
    	
    }
};