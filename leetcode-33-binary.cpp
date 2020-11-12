/**
 * 题解：33搜索旋转排序数组
 * 基本思想：二分法变体
 * 核心点：旋转点有且只有一个不是在搜索点的左侧就是右侧，又因为旋转点
 *         的两侧仍保持升序，所以搜索点的一侧一定保持升序。
**/
class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int n = nums.size();
    	int ans = -1;

    	/**处理边界条件**/
    	if (n == 0)
    		return ans;
    	if (n == 1)
    		ans = (nums[0] == target) ? 0 : -1;

    	/**主逻辑**/
    	int low = 0;
    	int high = n-1;
    	int mid;
    	while(low <= high){
    		mid = (high + low) / 2;
            if (nums[mid] == target) return mid;
    		//情况1：左有序右无序 即搜索点在旋转点左侧
    		if (nums[low] <= nums[mid])
    		{
    			if (nums[low] <= target && nums[mid] > target)
    				high = mid - 1;
    			else
    				low = mid + 1;
    		}else{
    		//情况2：右有序左无序 即搜索点在旋转点右侧
    			if (nums[mid] < target && nums[high] >= target)
    				low = mid + 1;
    			else
    				high = mid - 1;
    		}
    	}
    	return -1;
    }
};