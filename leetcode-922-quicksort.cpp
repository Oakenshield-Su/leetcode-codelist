class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        int low = 0, high = n - 1;
        

        //奇偶排序
        while(low < high){
            while(low < n && (A[low] & 1) == 0) low++;
            while(high >= 0 && (A[high] & 1) == 1) high--;
            if(low < high)
                swap(A[low], A[high]);   
        }
        
        //按位交换
        for(int i = 1, j = n-2; i < n/2; i = i + 2, j = j - 2){
            swap(A[i], A[j]);
        }
        return A;
    }
};