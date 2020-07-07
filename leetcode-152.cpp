/**
 * 乘积最大子序列
**/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	int length = nums.size();
    	if (length == 0)
    		return 0;
    	vector<int> dpMax(length);
    	vector<int> dpMin(length);

    	dpMax[0] = nums[0];
    	dpMin[0] = nums[0];

    	int max = nums[0];

    	for (int i = 1; i < length; ++i)
    	{
    		dpMax[i] = std::max(dpMin[i-1]*nums[i], std::max(dpMax[i-1]*nums[i], nums[i]));
    		dpMin[i] = std::min(dpMax[i-1]*nums[i], std::min(dpMin[i-1]*nums[i], nums[i]));
    		max = std::max(max, dpMax[i]);
    	}
    	return max;
    }
};