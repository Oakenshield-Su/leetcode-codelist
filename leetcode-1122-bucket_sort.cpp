/**
 * 1122.数组相对排序
 * 思路：桶排序
 * 固定数字用桶排序！！！！
 **/
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr2.size();
        int m = arr1.size();
        vector<int> bucket(1001, 0);
        vector<int> ans;

        for (int i = 0; i < m; i++)   //桶计数
            bucket[arr1[i]]++;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < bucket[arr2[i]]; j++)     //取出arr2对应的当前桶内数字
                ans.push_back(arr2[i]);

            bucket[arr2[i]] = 0;                          //当前桶清零
        }

        for (int i = 0; i < 1001; i++)
        {
            if (bucket[i] != 0)                          //当前桶内仍有数字说明不在相对顺序之内
            {
                for (int j = 0; j < bucket[i]; j++)
                    ans.push_back(i);
            }
        }
        return ans;
    }
};  