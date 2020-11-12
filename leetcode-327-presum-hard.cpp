/**
 * 327. 区间和的个数
 * 描述：给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，包含 lower 和 upper。
 *       区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。
 * 输入：nums = [-2,5,-1], lower = -2, upper = 2,
 * 输出：3
 * 解释：3个区间分别是: [0,0], [2,2], [0,2]，它们表示的和分别为: -2, -1, 2
**/

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<int> pre(n, 0);
        int ans = 0;

        if(n == 0) return ans;
        pre[0] = nums[0];
        for(int i = 1; i < n; i++)
            pre[i] = pre[i-1] + nums[i];
        
        return ans;
    }
};


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        //将目标区间变形，借助multiset求结果
        int res = 0;
        multiset<long long> S;//用来保存前缀和
        S.insert(0);//前0个数的和为0
        long long presum = 0;
        for(int i = 0; i < nums.size(); ++i){
            presum += nums[i];
            res += distance(S.lower_bound(presum - upper), S.upper_bound(presum - lower));
            S.insert(presum);
        }
        return res;
    }        
};