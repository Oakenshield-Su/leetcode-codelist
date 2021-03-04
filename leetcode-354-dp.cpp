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
 * 354. 俄罗斯套娃
 * 经典一维DP问题
**/
class Solution {
public:

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), 
                        [](const vector<int> &a, const vector<int> &b)-> bool{
                             return a[0] < b[0];
                        });
        vector<int> dp(n, 1);
        for(int cur = 1; cur < n; cur++){
            for(int k = 0; k < cur; k++){
                if( envelopes[cur][0] > envelopes[k][0] && envelopes[cur][1] > envelopes[k][1]) 
                //套娃问题不允许值相等的情况，所以左值排序后仍需关心左值相等的问题
                    dp[cur] = max(dp[k] + 1, dp[cur]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};