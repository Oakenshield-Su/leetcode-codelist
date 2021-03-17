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
 * 459.重复的子字符串
**/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.empty() || s.length() == 1)
            return false;
        
        int  n = s.length();
        int left;
        int right;
        for(int i = 1; i <= n/2; i++){       //重复子串的长度范围为[1, n/2]
            left = 0;
            right = i;
            if(n % i == 0){                  //约束1：字符串的长度为重复子串长度的整数倍
                while(s[left] == s[right]){  //约束2：子串A的每一位与其他子串的元素相同
                    if(right == n-1)         //结束条件：成功遍历检查所有子串
                        return true;
                    left++;
                    right++;
                }
            }
        }
        return false;
    }
};