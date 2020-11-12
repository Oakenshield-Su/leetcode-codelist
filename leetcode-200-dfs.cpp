/**
 * 200. 岛屿数量
 * 本质：连通分量的个数
 * 题解：深度优先遍历，一次深度优先遍历可以访问到一个岛屿的所有陆地，所以访问过后将陆地标记为0以防下次访问
 *      每个顶点都尝试作为深度优先遍历的起点，记录未访问起点的个数。
**/
class Solution {
public:
	const int dx[4] = {1, -1, 0,  0};
	const int dy[4] = {0,  0, 1, -1};
    int numIslands(vector<vector<char>>& grid) {
    	int n = grid.size();        //行数
    	int m = grid[0].size();     //列数
    	int ans = 0;

    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; j < m; ++j)
    		{
    			if (grid[i][j] == '1')
    			{
    				ans++;
    				dfs(grid, i, j);
    			}
    		}
    	}
    	return ans;
    }


    void dfs(vector<vector<char>>& grid, int i, int j){
    	if (grid[i][j] == '1')
    	{
    		grid[i][j] = '0';    //访问过后修改gird防止下次访问
    		for (int k = 0; k < 4; ++k){
    			int mx = i + dx[k], my = j + dy[k];
    			if (mx >= 0 && mx < grid.size() && my >= 0 && my < grid[0].size())
    			{
    				dfs(grid, mx, my);
    			}
    		}
    	}
    }
};