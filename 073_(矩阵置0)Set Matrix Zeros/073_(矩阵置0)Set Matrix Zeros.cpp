class Solution {
public:
    //常数空间
    //利用第一行和第一列存储其他零元素的行与列
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //row0 记录第一列是否有 0 元素
        //col0 记录第一行是否有 0 元素
        int row0 = -1, col0 = -1;
        for( int i = 0; i < m; i++ ){
            if(matrix[i][0] == 0) row0 = i;
            for( int j = 0; j < n; j++ ){
                if(i == 0 && matrix[i][j] == 0) col0 = j;
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
       
        //根据第一行、第一列记录的结果置 0 其所在的行与列的其他元素
        for( int i = 1; i < m; i++ ){
            for( int j = 1; j < n; j++ ){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        //校正第一列
        if(row0 != -1){
            for( int i = 0; i < m; i++) matrix[i][0] = 0;
        }
        //校正第一行
        if(col0 != -1){
            for( int j = 0; j < n; j++) matrix[0][j] = 0;
        }
    }
};