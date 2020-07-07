/**
 * 题解：连续的子数组和
**/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    	int n = nums.size();
    	if (n < 2)
    		return false;
    	vector<int> sum(n, 0);
    	sum[0] = nums[0];
    	for (int i = 1; i < n; ++i)        //计算前缀和
    		sum[i] = sum[i-1] + nums[i];

    	for (int start = 0; start < n-1; ++start)
    	{
    		for (int end = start + 1; end < n; ++end)
    		{
    			int sum_tmp = sum[end] - sum[start] + nums[start];
    			if (sum_tmp == k || (k != 0 && sum_tmp % k == 0))
    				return true;
    		}
    	}
    	return false;
    }
};

