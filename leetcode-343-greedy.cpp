/**
 * 题解：整数拆分（贪心算法）
**/
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n-1;        //边界条件：i=2,3的情况
        int three = n/3;  //整数n中3的个数

        if (n % 3 == 1) return pow(3, three-1)*2*2;     //拆分为...3*2*2

        if (n % 3 == 2) return pow(3, three)*2;       //拆分为...3*2

        return pow(3, three);           //拆分为...3
    }
};