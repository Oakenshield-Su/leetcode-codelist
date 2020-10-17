/**
 * 977.有序数组的平方
 * 双指针问题
**/
class Solution {
public:
	//从小到大
    vector<int> sortedSquares(vector<int>& A) {
    	int n = A.size();
    	vector<int> ans;
    	for (int i = 0; i < n; ++i)      //将A数组正数化
    		A[i] = abs(A[i]);

    	//寻找最小值
    	int min_loc = -1;
    	int min = INT_MAX;
    	for (int i = 0; i < n; ++i){
    		if (A[i] < min)
    		{
    			min = A[i];
    			min_loc = i;
    		}
    	}
    	ans.push_back(min*min);

    	//从最小值开始向外遍历（模仿归并排序）
    	int left = min_loc-1;
    	int right = min_loc+1;
    	while(left > -1 && right < n){
    		if (A[left] < A[right]){
    			ans.push_back(A[left]*A[left--]);
    		else
    			ans.push_back(A[right]*A[right++]);
    	}

    	while(left > -1) ans.push_back(A[left]*A[left--]);
    	while(right < n) ans.push_back(A[right]*A[right++]);


    	return ans;
    }

    //从大到小
    vector<int> sortedSquares(vector<int>& A){
    	int left = 0;
    	int right = A.size()-1;
    	int pos = A.size()-1;
    	vector<int> ans(A.size());

    	while(left <= right){
    		if (abs(A[left]) < abs(A[right]))
    			ans[pos] = A[right]*A[right--];
    		else
    			ans[pos] = A[left]*A[left++];
    		--pos;
    	}
    	return ans;
    }
};