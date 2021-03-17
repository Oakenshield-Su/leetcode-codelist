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
 * 1576.替换所有的问号
**/
class Solution {
public:
    
    string modifyString(string s) {
        if(s.empty()){
            return s;
        }
        
        int n = s.length();
        char basic;
        for(int i = 0; i < n; i++){
            basic = 'a';
            if(s[i] == '?'){
                //寻找前后非重复字符
                while(i - 1 >= 0 && s[i-1] == basic || i + 1 < n && s[i+1] == basic)
                    basic++;
                s[i] = basic;
            }
        }
        return s;
    }
};