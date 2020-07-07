/**
 * 题解：分割数组为连续子序列（贪心）
 * 描述：输入一个按升序排序的整数数组（可能包含重复数字），你需要将它们分割成几个子序列，
 *       其中每个子序列至少包含三个连续整数。返回你是否能做出这样的分割？
 * 思想：一个元素有三种情况：1.蕴含于长度大于3的子序列 
 							 2.蕴含于长度等于3的子序列
 							 3.情况1,2皆不满足
 	贪心策略：1.尽量让子序列变长
 	          2.无法变长时，形成长度为3的子序列
**/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
    	unordered_map<int, int> numCount;
    	unordered_map<int, int> tails;

    	for (auto num : nums)       //统计元素出现次数
    		numCount[num]++;

    	for (auto num : nums){
    		if (numCount[num] == 0) //元素num被消耗完
    			continue;
    		if (tails[num-1] > 0){      // 贪心策略1：尽量让子序列变长
    			tails[num-1]--;
    			tails[num]++;
    			numCount[num]--;
    		}else if(numCount[num+1] > 0 && numCount[num+2] > 0){     //贪心策略2：无法变长时，形成长度为3的子序列
    			numCount[num]--;
    			numCount[num+1]--;
    			numCount[num+2]--;
    			tails[num+2]++;
    		}else{
    			return false;
    		}
    	}
    	return true;
    }
};