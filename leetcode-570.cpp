class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSumMap;
        preSumMap[0] = 1;
        int preSum = 0;
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            preSum += nums[i];     //nums[0..i]前缀和
            if (preSumMap.find(preSum - k) != preSumMap.end())
                count += preSumMap[preSum - k];
            preSumMap[preSum]++;
        }
        return count;
    }
};