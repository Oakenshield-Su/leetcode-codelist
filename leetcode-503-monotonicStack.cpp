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
 * 503. 下一个更大元素（二）
 * tips1:下一个说明顺序寻找
 * tips2:更大说明要求有序
 * 使用单调栈来避免暴力法造成的浪费
 * 基础原理：单调递减的数组如6,5,4,3有相同的更大值如8  [6,5,4,3,8]
**/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> monotonicStack;

        for(int cur = 0; cur < 2*n - 1; cur++){
            while(!monotonicStack.empty() && nums[monotonicStack.top()] < nums[cur % n]){  //栈非空且当前元素大于栈顶元素则找到更大数，出栈
                res[monotonicStack.top()] = nums[cur % n];
                monotonicStack.pop();
            }
            monotonicStack.push(cur % n); ////栈非空且当前元素小于栈顶元素说明跟栈底层的数有相同的更大数，进栈
        }
        return res;    
    }
};