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
 * 59. 螺旋数组（二）
**/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0) return {};
        vector<vector<int>> res(n, vector<int>(n));

        //定义边界
        int up = 0, down = n - 1, left = 0, right = n - 1;
        int num = 1;

        while(true){
            for(int i = left; i <= right; i++)  res[up][i] = num++;     //从左到右遍历上边界
            if(++up > down) break;       //上边界向下移一维；   结束条件1：上边界越过下边界

            for(int i = up; i <= down; i++) res[i][right] = num++;    //从上到右遍历右边界
            if(--right < left) break;     //右边界向左移一维；   结束条件2：右边界越过左边界

            for(int i = right; i >= left; i--) res[down][i] = num++;   //从右到左遍历下边界
            if(--down < up) break;       //下边界向上移一维；     结束条件3：下边界越过上边界
 
            for(int i = down; i >= up; i--) res[i][left] = num++;      //从下到上遍历左边界
            if(++left > right) break;    //左边界向上移一维；     结束条件4：左边界越过右边界
        }
        return res;
    }
};