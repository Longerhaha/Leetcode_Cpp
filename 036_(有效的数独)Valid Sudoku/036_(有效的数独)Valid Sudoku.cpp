class Solution {
public:
    //validMat[0][idx1][idx2]代表第 idx1 行的 字符 idx2 + 1已经存在
    //validMat[1][idx1][idx2]代表第 idx1 列的 字符 idx2 + 1已经存在
    //validMat[2][idx1][idx2]代表第 idx1 块的 字符 idx2 + 1已经存在
    bool isValidSudoku(vector<vector<char>>& board) {
        bool validMat[3][9][9];
        for( int i = 0; i < 3; i++ ){
            for( int j = 0; j < 9; j++ ){
                for( int k = 0; k < 9; k++ ){
                    validMat[i][j][k] = false;
                }
            }
        }
        
        for( int i = 0; i < 9; i++ ){
            for( int j = 0; j < 9; j++ ){
                //跳过'.'
                if(board[i][j] == '.') continue;
                if(!validMat[0][i][(int)(board[i][j] - '1')] && !validMat[1][j][(int)(board[i][j] - '1')] && !validMat[2][i/3 * 3 + j / 3][(int)(board[i][j] - '1')]) {
                    validMat[0][i][(int)(board[i][j] - '1')] = true;
                    validMat[1][j][(int)(board[i][j] - '1')] = true;
                    validMat[2][i/3 * 3 + j / 3][(int)(board[i][j] - '1')] = true;
                }
                else return false;
            }
        }
        return true;
    }
};