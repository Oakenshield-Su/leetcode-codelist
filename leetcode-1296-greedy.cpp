/**
 * 题解：划分数组为连续数字的集合
**/
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
    	int n = nums.size();
    	if (n % k != 0)
	    	return false;
    	unordered_map<int, int> num_count;
    	sort(nums.begin(), nums.end());   
    	for (int i = 0; i < n; ++i)
    		num_count[nums[i]]++;
    	
    	for (int i = 0; i < n; ++i)
    	{
    		if (num_count[nums[i]] == 0)
    			continue;
    		else{
    			for (int j = 1; j < k; ++j)     //判断num[i]向后k-1个连续数字是否存在，如果不存在则失败，如果存在则该数消耗一次
    			{
    				if (num_count.count(nums[i]+j) == 0)   //nums[i]到nums[i]+k中间元素不存在
    					return false;
    				num_count[nums[i]+j]--;
    			}
    		}
    	}
    	return true;
    }
};