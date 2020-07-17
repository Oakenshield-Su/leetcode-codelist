/**
 * 解决重复问题：1.排序   例如：a<b<c则<a,b,c>确定后<a,c,b> <b,a,c>....<c,b,a>不会再出现
 *               2.每一重循环都判断元素相同           
**/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

    	int n = nums.size();
    	vector<vector<int>> ans;
    	sort(nums.begin(), nums.end());  //排序

    	
    	for (int first = 0; first < n; ++first)
    	{
    		if (nums[first] > 0)
    			return ans;
    		if (first > 0 && nums[first] == nums[first-1])    //避免重复元素
    			continue;
    		
    		int third = n-1;
    		int second =  first + 1;
    		while(second < third){
    			if (nums[first] + nums[second] + nums[third] == 0)
    			{
    				//跳过重复元素
    				while(second < third && nums[second] == nums[second+1]) second++;
    				while(second < third && nums[third] == nums[third-1]) third--;
    				ans.push_back({nums[first], nums[second], nums[third]});
    			}else if(nums[first] + nums[second] + nums[third] > 0){ //说明右指针元素过大
    				third--;       
    			}else{        //说明左指针元素过小
    				second++;
    			}
    		}
    	}
    	return ans;
    }
};