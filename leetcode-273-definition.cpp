/**
 * 273.移动零
 * */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        //定义非零数组
        int unZeros = 0;
        int cur = 0;
        for (; cur < n; cur++)
        {
            if (nums[cur] != 0)
                nums[unZeros++] = nums[cur];
        }
        for (; unZeros < n; unZeros++)
            nums[unZeros] = 0;
    }
};