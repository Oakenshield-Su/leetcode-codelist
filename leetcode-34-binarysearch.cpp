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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int n = nums.size();
        if(n == 0) return res;

        res[0] = binarySearch(nums, target, true);
        res[1] = binarySearch(nums, target, false);

        return res;
       
    }

    int binarySearch(const vector<int> &nums, int target, bool is_left_bound){
        int res = -1;
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                res = mid;
                if(is_left_bound)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }

        return res;
    }
};