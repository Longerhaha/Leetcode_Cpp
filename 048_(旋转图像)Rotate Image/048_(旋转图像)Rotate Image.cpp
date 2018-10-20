class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        
        //中间步
        //交换交错项 matrix[i][j], matrix[col_size - 1 - j][row_size - 1 - i]
        for( int i = 0; i < row_size - 1; i++ ){
            for( int j = 0; j < col_size - i - 1; j++ ){
                swap(matrix[i][j], matrix[col_size - 1 - j][row_size - 1 - i]);
            }
        }
        //前后交换行
        for( int i = 0; i < row_size / 2; i++ ){
            for( int j = 0; j < col_size; j++ ){
                swap(matrix[i][j], matrix[row_size - i - 1][j]);
            }
        }
        
    }
};