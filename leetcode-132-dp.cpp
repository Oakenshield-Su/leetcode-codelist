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
 * 132.分割回文串
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。返回符合要求的 最少分割次数 。
 * 经典DP问题
 * 必会点：动态规划预处理回文子串
**/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));

        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i+1][j-1];    
            }
        }

        vector<int> dp(n, INT_MAX);
        for(int i = 0; i < n; i++){
            if(isPalindrome[0][i])
                dp[i] = 0;
            else{
                for(int j = 0; j < i; j++){
                    if(isPalindrome[j+1][i])
                         dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};