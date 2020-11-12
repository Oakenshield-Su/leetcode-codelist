/**
 * 每日一题：845 最长山脉
 * 思路：山顶即左、右边全部小于，且连续。如果中间有间断则从零开始。
**/

class Solution {
public:
    int longestMountain(vector<int>& A) {
    	int n = A.size();
    	int ans = 0;
    	if (n < 3) return ans;
    	vector<int> left(n);
    	vector<int> right(n);

    	left[0] = 0;
    	for (int i = 1; i < n; ++i)
    		left[i] = (A[i] > A[i-1]) ? left[i-1]+1 : 0;

    	right[n-1] = 0;
    	for (int i = n-2; i > 0; --i)
    		right[i] = (A[i] > A[i+1]) ? right[i+1]+1 : 0;

    	for (int i = 0; i < n; ++i)
    	{
    		if (left[i] > 0 && right[i] > 0)
    			ans = max(ans, left[i]+right[i]+1);
    	}

    	return ans;
    }
};