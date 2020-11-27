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
 * 454. 四数相加
 * 分组+哈希
 * 核心：A + B + C + D = 0 ---> A + B = 0 - C - D
**/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> map;

        for (int i = 0; i < A.size(); i++)
        {
           for (int j = 0; j < B.size(); j++)
           {
               map[A[i] + B[j]]++;       //记录key为A+B的元素个数
           }
        }

        int ans = 0;
        for (int i = 0; i < C.size(); i++)
        {
           for (int j = 0; j < D.size(); j++)
           {
               ans += map[-C[i]-D[j]]; //寻找key满足A + B = 0 - C - D的元素个数
           }
        }
        return ans;
    }

    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
        unordered_map<int, int> map;
        
        for(const auto &a : A)
            for(const auto &b : B)
                map[a + b]++;
        
        int ans = 0;
        for(const auto &c : C)
            for(const auto &d : D)
                ans += map[-(d + c)];
        
        return ans;
    }
};