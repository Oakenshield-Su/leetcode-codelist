/**
 * 题解: 拼接最大数（划分问题规模+单调栈）
**/
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    	int nums1_size = nums1.size();
    	int nums2_size = nums2.size();
    	vector<int> res(k);

    	for (int i = 0; i <= k; ++i)      //划分子问题：nums1包含i个数字,nums2包含k-i个数字
    	{ 
    		if (i > nums1_size || k-i >nums2_size)    
    			continue;
    		vector<int> tmp;         //中间结果

    		vector<int> nums1_tmp = maxSquence(nums1, nums1_size, i);
    		vector<int> nums2_tmp = maxSquence(nums2, nums2_size, k-i);

    		//归并
    		auto it_nums1 = nums1_tmp.begin();
    		auto it_nums2 = nums2_tmp.begin();
    		while(it_nums1 != nums1_tmp.end() || it_nums2 != nums2_tmp.end()){
    			tmp.push_back(lexicographical_compare(it_nums1, nums1_tmp.end(), it_nums2, nums2_tmp.end()) ? *it_nums2++ : *it_nums1++);
    		}

    		//比较
    		res = lexicographical_compare(tmp.begin(), tmp.end(), res.begin(), res.end()) ? res : tmp;
    	}
    	return res;
    }

    vector<int> maxSquence(vector<int>& nums, int n, int k){
    		vector<int> squence;
    		int pop = n-k;   //删除元素个数
    		for (int i = 0; i < n; ++i)
    		{
    			while(!squence.empty() && nums[i] > squence.back() && pop-- > 0){ //出栈条件
    				squence.pop_back();
    			}
    			squence.push_back(nums[i]);     //入栈
    		}

    		//注意：pop此时可能不为0 比如nums全部单减
            squence.resize(k);
    		return squence;
    }
};