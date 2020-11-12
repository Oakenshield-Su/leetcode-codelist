/**
 * 1356:根据数字二进制下 1 的数目排序
 * 描述：给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。
 * 如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。
 * 思路1：桶排序
 * 思路2：C++原生排序+比较器
**/
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        vector<vector<int>> sortedOne(32, vector<int>());   // int为32位整数，所以定义32个桶
        int n = arr.size();

        for(int i = 0; i < n; i++){
            bitset<sizeof(int)*8> ones(arr[i]);
            sortedOne[ones.count()].push_back(arr[i]);     //记录第i个桶内元素
        }

        for(int i = 0; i < 32; i++){
            sort(sortedOne[i].begin(), sortedOne[i].end());   //桶内升序排序
            for(auto k : sortedOne[i])
                ans.push_back(k);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int x, int y) {
            int cx = __builtin_popcount(x);
            int cy = __builtin_popcount(y);
            if (cx != cy) return cx < cy;   //当二进制中数字1的个数不等时数字1多的在后
            return x < y;                   //当二进制中数字1的个数相等时数字大的在后
        });
        return arr;
    }
};