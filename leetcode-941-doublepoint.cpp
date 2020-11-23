/**
 * 941. 有效山峰
 **/
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        //左右两边找山峰
        int n = arr.size();
        int left = 0, right = n-1;

        while(left+1 < n && arr[left] < arr[left+1])
            left++;

        while(right-1 >= 0 && arr[right-1] > arr[right] )
            right--;
        
        return left > 0 && right < n-1 && right == left;
    }
};