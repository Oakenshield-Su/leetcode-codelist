class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    	int rowSize = triangle.size();
    	vector<vector<int>> dp(triangle);
    	int minimum = 0;
    	if (triangle.size() == 1) {
            return triangle[0][0];
        }
    	//第一 二行边界条件处理
    	dp[0][0] = triangle[0][0];
    	dp[1][0] = triangle[1][0] + dp[0][0];
    	dp[1][1] = triangle[1][1] + dp[0][0];

    	for (int i = 2; i < rowSize; ++i)
    	{
    		for (int j = 0; j < triangle[i].size(); ++j)
    		{
    			if (j==0) //三角形最左边
    				dp[i][j] = dp[i-1][j] + triangle[i][j];
    			else if (j == triangle[i].size()-1) //三角形最右边
	    			dp[i][j] = dp[i-1][j-1] + triangle[i][j];
    			else
    				dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
    		}
    	}
    	minimum = *std::min_element(dp[rowSize-1].begin(), dp[rowSize-1].end());
    	return minimum;
    }
};