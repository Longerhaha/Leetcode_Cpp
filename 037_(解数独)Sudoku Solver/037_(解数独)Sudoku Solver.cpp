class Solution {
public:
    const int SudokuSize = 9;
    const int SudokuSizeBlock = 3;
    bool validMat[3][9][9];
    
    bool solveSudoku_dfs(vector<vector<char>>& board, int row_idx, int col_idx){
        if(row_idx == SudokuSize && col_idx == SudokuSize - 1) return true;
        if(row_idx == SudokuSize) return solveSudoku_dfs(board, 0, col_idx + 1);
        
        if(board[row_idx][col_idx] != '.'){
            return solveSudoku_dfs(board, row_idx + 1, col_idx);
        }
        else{
            for( int k = 1; k <= SudokuSize; k++ ){
                //如果合理
                if(!validMat[0][row_idx][k - 1] && !validMat[1][col_idx][k - 1] && !validMat[2][row_idx/SudokuSizeBlock * SudokuSizeBlock + col_idx / SudokuSizeBlock][k - 1]){
                    //设置
                    validMat[0][row_idx][k - 1] = true;
                    validMat[1][col_idx][k - 1] = true;
                    validMat[2][row_idx / SudokuSizeBlock * SudokuSizeBlock + col_idx / SudokuSizeBlock][k - 1] = true;
                    board[row_idx][col_idx] = k + '0';
                    if(solveSudoku_dfs(board, row_idx + 1, col_idx)) return true;
                    else{
                        //探测发现不是合理的选择则重置，继续探测下个数
                        validMat[0][row_idx][k - 1] = false;
                        validMat[1][col_idx][k - 1] = false;
                        validMat[2][row_idx / SudokuSizeBlock * SudokuSizeBlock + col_idx / SudokuSizeBlock][k - 1] = false;
                        board[row_idx][col_idx] = '.';
                    }  
                }   
            }
        }
        //不合理则返回false
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        for( int i = 0; i < 3; i++ ){
            for( int j = 0; j < SudokuSize; j++ ){
                for( int k = 0; k < SudokuSize; k++ ){
                    validMat[i][j][k] = false;
                }
            }
        }
        
        for( int i = 0; i < SudokuSize; i++ ){
            for( int j = 0; j < SudokuSize; j++ ){
                //跳过'.'
                if(board[i][j] == '.') continue;
                if(!validMat[0][i][(int)(board[i][j] - '1')] && !validMat[1][j][(int)(board[i][j] - '1')] && !validMat[2][i/SudokuSizeBlock * SudokuSizeBlock + j / SudokuSizeBlock][(int)(board[i][j] - '1')]) {
                    validMat[0][i][(int)(board[i][j] - '1')] = true;
                    validMat[1][j][(int)(board[i][j] - '1')] = true;
                    validMat[2][i/SudokuSizeBlock * SudokuSizeBlock + j / SudokuSizeBlock][(int)(board[i][j] - '1')] = true;
                }
            }
        }
        
        solveSudoku_dfs(board, 0, 0);
        
    }
};