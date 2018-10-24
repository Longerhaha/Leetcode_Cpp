class Solution {
public:
    /*按如如下的方式按圈添加数据
              （上行）
             ----------
    left_col |        | right_col
             |        |
             |--------|
              （下行）
    比如：
    [
     [ 1, 2, 3 ],
     [ 4, 5, 6 ],
     [ 7, 8, 9 ]
    ]
    第一圈添加：上行1,2,3 右列6,9 下行8 左列7,4 
    第二圈 5
    */
    void draw_cycle(vector<vector<int>>& matrix, const int size, const int center, int& cnt){
        int end_col = center + (size - 2 * center) - 1;
        int end_row = center + (size - 2 * center) - 1;
        for( int i = center; i <= end_col; i++ )
            matrix[center][i] = ++cnt;
        for( int i = center + 1; i <= end_row; i++ )
            matrix[i][end_col] = ++cnt;
        //end_row > center 防止当前圈是单行的特殊情况
        for(int i = end_col - 1; i > center && end_row > center; i-- )
            matrix[end_row][i] = ++cnt;
        //end_col > center 防止当前圈是单列的特殊情况
        for(int i = end_row; i >= center + 1 && end_col > center; i-- )
            matrix[i][center] = ++cnt;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        if(n == 0) return matrix;
        int total_len = n * n;
        //转圈的数目
        int circle = 0;
        //中心点(center, center)
        int center = 0;
        int cnt = 0;
        while( n >= 2 * circle + 1 && n >= 2 * circle + 1 ){
            draw_cycle(matrix, n, center, cnt);
            circle++, center++;
        }
        return matrix;
    }
};