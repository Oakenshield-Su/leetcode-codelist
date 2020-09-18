class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
    	int n = mat.size();
    	int m = mat[0].size();
    	vector<int> cRow(n);   //记录每一行1的个数
    	vector<int> cCol(m);   //记录每一列1的个数	
    	int ans = 0;

    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; j < m; ++j)
    		{
    			if (mat[i][j] == 1)
    			{
    				cRow[i]++;
    				cCol[j]++;
    			}
    		}
    	}

    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; j < m; ++j)
    		{
    			if (cRow[i] == 1 && cCol[j] == 1 && mat[i][j] == 1)
    				ans++;
    		}
    	}
    	return ans;
    }
};