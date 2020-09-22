/**
 * 题解：0/1矩阵
 * 方案：多源BFS
 * 思路：利用超级零思想，虚构一个超级节点，该超级节点的子节点为0节点，然后每访问一次dis+1
 * 注意点：
 * 1. Tree 只有 1 个 root，而图可以有多个源点，所以首先需要把多个源点都入队；
 * 2. Tree 是有向的因此不需要标识是否访问过，而对于无向图来说，必须得标志是否访问过哦！
 * 并且为了防止某个节点多次入队，需要在其入队之前就将其设置成已访问！
**/
class Solution {

private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	int m = matrix[0].size();
    	vector<vector<int>> dist(n, vector<int>(m, 0));
    	vector<vector<bool>> visited(n, vector<bool>(m, false));
    	queue<pair<int, int>> q;

    	//0节点加入搜索树
    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = 0; j < m; ++j)
    		{
    			if (matrix[i][j] == 0)
    			{
    				q.emplace(i, j);
    				visited[i][j] = true;
    			}
    		}
    	}

    	while(!q.empty()){
    		auto [i, j] = q.front();
    		q.pop();

    		for (int k = 0; k < 4; ++k)
    		{
    			int ni = i + dirs[k][0];
    			int nj = j + dirs[k][1];
    			if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj])     //访问下一层节点
    			{
    				dist[ni][nj] = dist[i][j] + 1;
    				q.emplace(ni, nj);
    				visited[ni][nj] = true;	
    			}
    		}
    	}

    	return dist;
    }
};