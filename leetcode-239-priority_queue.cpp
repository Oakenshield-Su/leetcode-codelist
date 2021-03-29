#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * 239.滑动窗口最大值
 * 优先队列法
**/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> max_heap;
        vector<int> res;
        for(int i = 0; i < k-1; i++){
            max_heap.push({nums[i], i});
        }

        int n = nums.size();
        for(int i = k-1 ; i < n; i++){
            max_heap.push({nums[i], i});
            while(max_heap.top().second < i - k + 1){
                max_heap.pop();
            }
            res.push_back(max_heap.top().first);
        }

        return res;
    }
};