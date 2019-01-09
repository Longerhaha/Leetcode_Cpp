class Solution {
public:
    //函数中涉及到的c++知识
    //vector<vector<char>> board 是个长度、宽度可变的二维 char 数组，c++里面称为容器
    //board.size() 可以获取行数， board[0].size() 可以获取列数
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row == 0) return ;
        int col = board[0].size();
        if(col == 0) return ;
        //上下边界DFS
        for( int j = 0; j < col; j++ ){
            DFS(board, 0, j);
            DFS(board, row-1, j);
        }
        //左右边界DFS
        for( int i = 1; i < row - 1; i++ ){
            DFS(board, i, 0);
            DFS(board, i, col-1);
        }
        //根据遍历结果重新更新结果
        //如果是 '*' 则说明该点与边界的 'O' 相连，于是需要更新为 'O'
        //如果是 'O' 则说明该点不与边界的 'O' 相连，于是需要更新为 'X'
        for( int i = 0; i < row; i++ ){
             for( int j = 0; j < col; j++ ){
                 if(board[i][j] == 'O') board[i][j] = 'X';
                 else if(board[i][j] == '*') board[i][j] = 'O';
             }
        }
        
    }
    void DFS(vector<vector<char>>& board, int i, int j){
        //越界或者不是与边界0相连的0则返回
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') return ;
        //其他情况就是与边界0相连的0，然后标记为'*'
        board[i][j] = '*';
        DFS(board, i - 1, j);
        DFS(board, i + 1, j);
        DFS(board, i , j - 1);
        DFS(board, i , j + 1);
    }
};