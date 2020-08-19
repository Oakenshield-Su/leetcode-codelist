class Solution {
    int m, n;
    boolean[][] visited;
    private int d[][] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    public void solve(char[][] board) {
        if(board.length == 0){
            return;
        }
        m = board.length;
        n = board[0].length;
        visited = new boolean[m][n];
        //首先找到所有跟外界相连的O
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                boolean isEdge = i == 0 || j == 0 || i == m - 1 || j == n - 1;
                if(!isEdge)      //非边界
                	continue;
                if (board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }
        //未与边界'O'相连的'O'修改为'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }


    public void dfs(char[][] board, int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {       //good code
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if (inArea(newx, newy) && !visited[newx][newy] && board[newx][newy] == 'O') {
                dfs(board, newx, newy);
            }
        }
    }

    private boolean inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
}