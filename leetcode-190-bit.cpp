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
 * 160.翻转二进制
**/

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;
        for (int i = 0; i < 32 && n > 0; i++)// n > 0是个优化，当n=0时没有循环的必要因为res初始化全0
        {   
            res |= (n & 1) << (31 - i);
            n >>= 1;
        }
        return res;
    }
};