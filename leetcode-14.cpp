/**
 * 剪绳子问题（动态规划）
**/

class Solution {
public:
    int cuttingRope(int n) {
    	if(n < 2)
            return 0;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;

        int* products = new int[n + 1];
        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;

        int maxProduct = 0;
        int product = 0;
        for (int i = 4; i <= n; ++i)
        {
            maxProduct = 0;
            product = 0;               // init again
            for (int j = 1; j <= i/2; ++j)
            {
                product = products[j] * products[i-j];
                if (maxProduct < product)         // find max(f(j) + f(i-j))
                {
                    maxProduct = product;
                }
            }
            products[i] = maxProduct;       // max(f(j) + f(i-j)) equal f(i)
        }
        maxProduct = products[n];
        delete[] products;
        return maxProduct;
    }
}; 
