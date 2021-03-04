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
 *
**/
class Solution {
public:
    //单调栈
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        if (nums.size() == k) return nums;
        int n = nums.size();
        vector<int> ans;
        for (int i=0; i < n; i++) {
            //当nums[i]是一个比栈顶更小的元素时，不停地弹栈直到当前栈顶更小
            //此处需要另外判断数组剩余长度够不够填满栈，不然最后答案长度可能会小于k
            while (ans.size() > 0 && ans.back() > nums[i] && ans.size() + n - i - 1 >= k) {
                ans.pop_back();
            }
            if (ans.size() < k) ans.push_back(nums[i]);
        }
        return ans;
    }
};