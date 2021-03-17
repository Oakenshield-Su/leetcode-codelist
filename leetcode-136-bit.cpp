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
 * 136.只出现一次的数字
 * 1.元素a与0异或得到元素本身
 * 2.元素a与本身异或得到0
**/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(const auto &num : nums){
            ans ^= num;
        }
        return ans;
    }
};