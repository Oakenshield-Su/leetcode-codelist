/**
 * 题解：1365 有多少小于当前数字的数字
 * 思路：桶排序
 *
**/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> bucket(101);    //0-100个桶

        for(int i = 0; i < n; i++)  //记录词频
            bucket[nums[i]]++;
        
        for(int k = 1; k < 101; k++)
            bucket[k] += bucket[k-1];    //前缀和，记录[0, k]区间内出现数的个数和
        
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
            ans[i] = (nums[i] == 0) ? 0 : bucket[nums[i]-1];   //[0, i-1]的个数和 ，0除外
        
        return ans;
    }
};