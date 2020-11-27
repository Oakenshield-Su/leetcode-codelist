#include <vector>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * 164. 最大间距
**/
class Solution {
public:
    //sort基础版
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        if(n < 2) return ans;

        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; i++){
            ans = max(ans, abs(nums[i] - nums[i-1]));
        }

        return ans;
    }

    //桶排序版
};