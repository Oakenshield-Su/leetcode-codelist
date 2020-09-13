/**
 * 题解：单词搜索 有返回结果的DFS
 * 难点：边界条件，例如['a'] 'a'
 * 未掌握点：递归
 *
 * DFS代码模板
 * void dfs()//参数用来表示状态  
 * {  
 *   if(到达终点状态)  
 *   {  
 *       ...//根据题意添加  
 *       return;  
 *   }  
 *   if(越界或者是不合法状态)  
 *       return;  
 *   if(特殊状态)//剪枝
 *       return ;
 *   for(扩展方式)  
 *   {  
 *       if(扩展方式所达到状态合法)  
 *       {  
 *           修改操作;//根据题意来添加  
 *           标记；  
 *           dfs（）；  
 *           (还原标记)；  
 *           //是否还原标记根据题意  
 *           //如果加上（还原标记）就是 回溯法  
 *       }  
 *
 *   }  
 * }  
**/
class Solution {
public:
	const int dx[4] = {0, 1, 0, -1};
	const int dy[4] = {1, 0, -1, 0};
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())                     //边界判断
        	return true;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));  //访问数组
        for (int i = 0; i < board.size(); ++i)
        	for (int j = 0; j < board[0].size(); ++j)				//矩阵中每一个元素作为单词起点
        		if(dfs(board, i, j, word, 0, visited))             
        			return true;
      	return false;
    }

    bool dfs(vector<vector<char>>& board, int x, int y, string& word, int index, vector<vector<bool>>& visited){
    	if (word.size() == index)      //结束状态:遍历到单词最后一个字母以后返回
    		return true;
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())  //越界处理
            return false;

        if (board[x][y] == word[index] && !visited[x][y])
    	{
            visited[x][y] = true;             //设置访问位
    		for (int i = 0; i < 4; ++i)
    		{
    			int mx = x + dx[i], my = y + dy[i];
                if(dfs(board, mx, my, word, index + 1, visited))     //子节点中搜索到单词子串后返回true
    				return true;
    		}
            visited[x][y] = false;          //子节点中未搜索到单词子串后清除访问位，以便其他搜索操作正常进行
    	}
    	return false;
    }
};