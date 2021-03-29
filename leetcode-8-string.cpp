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
 * 8.字符串翻转
**/
class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int sign = 1;
        int used_index = -1;
        int res = 0;
        int digit = 0;

        //去除空格
        for(int i = 0; i < n; i++){
            if(s[i] == ' ')
                used_index++;
            else
                break;
        }
        //正负号
        if(used_index + 1 < n && (s[used_index + 1] == '+' || s[used_index + 1] == '-')){
            sign = (s[++used_index] == '-') ? -1 : 1;
        }

        //去除前导零
        while(used_index + 1 < n && s[used_index + 1] == '0'){
            used_index++;
        }


        //处理数字串
        for(int i = used_index + 1; i < n; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                digit = s[i] - '0';
                if(res > (INT_MAX - digit) / 10)       //tips: 表达式右移防止res越界
                    return (sign == -1) ? INT_MIN : INT_MAX;
                res = res * 10 + (s[i] - '0');
            }else{
                //非零元素结束
                break;
            }
        }
        
        res = sign * res;
        return res;
    }
};