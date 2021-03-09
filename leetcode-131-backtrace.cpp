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
 * 131.分割回文串
 * 题目描述：给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 * 回溯
**/


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        backtracing(s, res, {});
        return res;
    }

    void backtracing(string s, vector<vector<string>> &res, vector<string> &path){
        if(s.empty()){//满足题目要求且无法继续遍历
            res.push_back(path);
            return;
        }
        for (int i = 1; i <= s.size(); i++)
        {
            string sub_res = s.substr(0, i);
            if (isPalindrome(sub_res))
            {
                path.push_back(sub_res);
                dfs(s.substr(i), res, path);
                path.pop_back();
            }
        }
        return;
    }

    bool isPalindrome(string a){
        int n = a.length();
        int left = 0;
        int right = n - 1;
        while(left < right){
            if(string[left++] != string[right--])
                return false;
        }
        return true;
    }
};

