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
 * 647.回文子串
**/
class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty()) return 0;
        int res = 0;

        int n = s.length();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                isPalindrome[i][j] = isPalindrome[i+1][j-1] && (s[i] == s[j]);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome[i][j])
                    res++;
            }
        }
        return res;
    }

    //滑动窗口优化内存
    int countSubstrings(string s) {
        if(s.empty()) return 0;
        int n = s.length();
        int res = n;
        vector<bool> isPalindrome(n, true);
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j > i; j--){
                isPalindrome[j] = isPalindrome[j-1] && (s[i] == s[j]);
                if(isPalindrome[j])
                    res++;
            }
        }

        
        return res;
    }
};