class Solution {
public:
    int arrangeCoins(int n) {
        int res = 0;
        int m = n/2+1;        //i最多取 n/2+1
        for(int i = 1; i <= m; i++){
            if(i > n) break;
            n -= i;
            res += 1;
        }
        return res;
    }
};