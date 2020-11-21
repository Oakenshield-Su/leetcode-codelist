class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) 
            return n;

        //定义非重复数组尾指针
        int unDuplicates = 0;
        int cur = unDuplicates + 1;
        for (; cur < n; cur++)
        {
            if (nums[unDuplicates] != nums[cur])
                nums[++unDuplicates] = nums[cur];
        }
        return unDuplicates+1;
    }
};