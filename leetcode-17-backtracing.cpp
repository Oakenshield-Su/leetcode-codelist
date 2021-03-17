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
 * 17. 电话号码
**/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> res;
        string path;
        backtracing(res, phoneMap, path , digits, 0);
        return res;
    }

    void backtracing(vector<string> &res, const unordered_map<char, string> &phoneMap, string &path, const string &digits, int i){
        if(i == digits.length()){
            res.push_back(path);
            return;
        }else{
            char index = digits[i];
            const string &s = phoneMap.at(index);
            for(const auto &c : s){
                path.push_back(c);
                backtracing(res, phoneMap, path, digits, i+1);
                path.pop_back();
            }
        }
    }
};