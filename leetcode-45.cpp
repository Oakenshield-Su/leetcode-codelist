/**
 * 题解：跳跃问题二
 * 贪心算法:从前向后不断扩展可达数组
**/
class Solution {
public:
    int jump(vector<int>& nums) {
    	int length = nums.size();
    	if (length <= 1)
    		return 0;

    	int end = 0; //当前可达位置
    	int steps = 0;
        int maxJumpDistance = 0;
    	for (int i = 0; i < length; ++i)
        {
            maxJumpDistance = max(maxJumpDistance, nums[i]+i);
            if (end == i)    //需再次起跳
            {
                end = maxJumpDistance;
                steps++;
            }
        }
    	
    	return steps-1;
    }
};