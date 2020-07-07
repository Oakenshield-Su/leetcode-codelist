/**
 * 题解：跳跃问题二
 * 贪心算法:从后向前（超出时间）
**/
class Solution {
public:
    int jump(vector<int>& nums) {
    	int length = nums.size();
    	if (length <= 1)
    		return 0;

    	int index = length-1; //当前可达位置
    	int steps = 0;
    	while(index != 0){
    		for (int i = 0; i < index; ++i)
    		{
    			if (nums[i] >= index - i)
    			{
    				index = i;
    				steps++;
    				break;
    			}
    		}
    	}
    	
    	return steps;
    }
};