class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    	unordered_map<int, int> map;
    	map[0] = 1;

    	int sum = 0;
    	int ans = 0;
    	for (auto num : nums){
    		sum += num & 1;      // 学习
    		ans += (sum >= k) ? map[sum - k] : 0;
    		map[sum]++;
    	}
    	return ans;
    }
};