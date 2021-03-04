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
 * 493.翻转对
**/
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        if(n <= 1) return ans;

        auto end = nums.end();
        auto left = nums.end() - 2;
        auto right = nums.end() - 1;
        while (left >= nums.begin())
        {
            auto cur = right;
            while(cur != end && *left > (long long)2 * (*cur))  //注意溢出问题
            {
                ans++;
                cur++;
            }
            right--;
            left--;
            sort(right, end);
        }
        return ans;
    }
};