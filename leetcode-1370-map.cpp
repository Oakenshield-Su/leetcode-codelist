#include <vector>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

/**
 * 1370.上升下降字符串
**/
class Solution {
public:
    string sortString(string s) {
        int word_count[26]={0};    //注意初始化
        for(char c : s){
            word_count[c - 'a']++;
        }

        string ans;
        while(ans.length() < s.length()){     //结束条件没有想到
            //向前遍历一遍
            for(int i = 0; i < 26; i++){
                if(word_count[i] > 0){
                    ans += 'a'+i;
                    word_count[i]--;
                }
            }
            //向后遍历一遍
            for(int i = 25; i >= 0; i--){
                if(word_count[i] > 0){
                    ans += 'a'+i;
                    word_count[i]--;
                }
            }
        }
        return ans;
    }
};