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
 * 169.超过一半元素
 * 选举法
**/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mode = -1;
        int count = 0;

        for(const auto &num : nums){
            if(num == mode){
                 count++;
            }else{
                count--;
                if(count < 0){
                    mode = num;
                    count = 1;
                }
            }
        }
        return mode;
    }
};