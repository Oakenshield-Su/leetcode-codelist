/**
 * 349.两个数组的交集
 * 核心：去重
**/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        unordered_map<int, int> nums1_map;

        for(int i = 0; i < n; i++)                            //nums1记录到map中去重
            nums1_map[nums1[i]] = 0;
        
        for(int i = 0; i < m; i++){
            if(nums1_map.find(nums2[i]) != nums1_map.end())  //查找是否key值已存在，如果key值存在说明该元素为并集中的元素
                nums1_map[nums2[i]]++;                       //记录次数，起去重的效果
        }
            

        auto it = nums1_map.begin();
        while(it != nums1_map.end()){
            if(it->second != 0)
                ans.push_back(it->first);
            it++;
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};