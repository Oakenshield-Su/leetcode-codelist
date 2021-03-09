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
 * 1047. 删除重复字符
 * 
**/

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> uniqueChars;

        string res;
        for(auto c : S){
            if(!res.empty()){          //栈不为空
                if(res.back() == c){           //元素相等时当前元素不进栈且栈顶元素出栈
                    res.pop_back();
                }else{                                //元素不等时当前元素进栈
                    res.push_back(c);
                }
            }else{               //栈为空
                res.push_back(c);            //当前元素进栈
            }
        }
        return res;
    }
};