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
 * 118.杨辉三角
 * 当前元素等于上一层的两元素之和
**/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> angle(numRows);

        for(int i = 0; i < numRows; i++){
            angle[i].resize(i+1);
            angle[i][0] = angle[i][i] = 1;
            for(int j = 1; j < i; j++){
                angle[i][j] = angle[i-1][j-1] + angle[i-1][j];
            }
        }
        return angle;
    }
};