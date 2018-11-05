class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;
        //二分查找 target 可能所在的行
        int row_start = 0;
        int row_end = m - 1;
        int row = 0;
        while( row_start < row_end - 1 ){
            int row_mid = (row_start + row_end) / 2;
            if(matrix[row_mid][0] > target) row_end = row_mid - 1;
            else row_start = row_mid;
        }
        row = target >= matrix[row_end][0] ? row_end : row_start;
        //二分查找 target 在第 row 行中是否存在
        int col_start = 0, col_end = n - 1;
        while( col_start < col_end ){
            int col_mid = (col_start + col_end) / 2;
            if(matrix[row][col_mid] == target) return true;
            else if(matrix[row][col_mid] > target) col_end = col_mid - 1;
            else col_start = col_mid + 1;
        }
        return matrix[row][col_start] == target;
    }
};