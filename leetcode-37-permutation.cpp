/**
 * 37. 下一个排列
 * 排列问题要点：1.升序时数字最大  2.降序时数字最小
 * 思路：1.从个位数开始寻找第一个降序点，因为降序点之后是升序序列此时数字最大已经无法更大。
 *       2.如果想要数字变大且变大的幅度尽量小，就需要从升序序列里找到一个刚刚比降序点大的数进行交换
 *       3.交换后数字变大但是升序的特点导致交换点之后仍有下降空间，所以降序排列
**/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size();

    	//寻找降序点
    	int down = n - 2;
    	while(down >= 0 && nums[down] >= nums[down + 1])
    		down--;

    	
        int k = n - 1;
    	if (down >= 0)
    	{
    		//在升序序列中寻找略大于降序点的值
    		while(k > down && nums[k] <= nums[down]){
    			k--;
    		}
    		swap(nums[k], nums[down]);
    	}

    	//降序排列
    	reverse(nums.begin() + down + 1, nums.end());
    }
};