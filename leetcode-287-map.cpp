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
 * 287.寻找重复数
 * 方法1：map法，建立位置和值的映射关系(不至一种方法)
**/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<bool> map(n+1, false);
        int res = -1;

        for(const auto &num : nums){
            if(!map[num])
                map[num] = true;
            else
                res = num;
        }
        return res;
    }
};