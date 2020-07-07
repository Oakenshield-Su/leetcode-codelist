/**
 * 题解：N皇后问题
 * 回溯剪枝	
**/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> seq(n);  //N皇后全排列序列
        vector<bool> visited(n, false);
        //回溯N皇后序列
        solveNQueensDFS(res, seq, visited, 0, n);
        return res;

    }

    /**生成N皇后问题单个解**/
    void generateNQuenen(vector<vector<string>> &res, vector<int> seq, int n){
    	vector<string> oneQuenen;
    	for (int i = 0; i < n; ++i)
    	{
    		string path(n,'.');
    		for (int j = 0; j < n; ++j)
    		{
    			if (seq[i] == j)
    				path[j] = 'Q';
    		}
    		oneQuenen.push_back(path);
    	}
    	res.push_back(oneQuenen);
    }

    /**检查第index行第seq[index]列是否合法**/
    void solveNQueensDFS(vector<vector<string>> &res, vector<int> &seq, vector<bool> &visited, int index, int n){
    	if (index == n){
    		generateNQuenen(res, seq, n);
    		return;
    	}
    	for (int i = 0; i < n; ++i)  //遍历所有列
    	{
    		if (!visited[i])    //第i列无皇后
    		{
    			bool notConflict = true;         //对角线是否存在冲突，如果冲突则跳出循环达到剪枝目的
    			for (int j = 0; j < index; ++j)      
    			{
    				//第index行列号暂时为i,第j行的列号为seq[j]
    				if (abs(index - j) == abs(i - seq[j]))  //行号之差与列号之差的绝对值相等（剪枝）
    				{
    					notConflict = false;
    					break;
    				}
    			}

    			if (notConflict)
    			{
    				visited[i] = true;      //当前解的第i行已被访问
    				seq[index] = i;        //记录第index行第i列放置皇后
    				solveNQueensDFS(res, seq, visited, index+1, n);
    				visited[i] = false;     //修改被访问位，便于其他解可以重复使用
    			}

    		}
    	}
    }
};