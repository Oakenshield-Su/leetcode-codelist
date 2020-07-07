/**
 * 跳跃问题：从右往左
**/
class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int length = nums.size();
        int index = length - 1;

        for (int i = length - 2; i >= 0; --i)
        {
            if (nums[i] >= index - i)
                index = i;
        }
        return index == 0 ? true : false;
    }
};