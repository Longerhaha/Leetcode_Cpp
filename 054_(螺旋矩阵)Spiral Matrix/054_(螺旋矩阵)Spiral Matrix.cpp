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
    void draw_cycle(vector<int> &ans, const vector<vector<int>>& matrix, const int row, const int col, const int center){
        int end_col = center + (col - 2 * center) - 1;
        int end_row = center + (row - 2 * center) - 1;
        for( int i = center; i <= end_col; i++ )
            ans.push_back(matrix[center][i]);
        for( int i = center + 1; i <= end_row; i++ )
            ans.push_back(matrix[i][end_col]);
        //end_row > center 防止当前圈是单行的特殊情况
        for(int i = end_col - 1; i > center && end_row > center; i-- )
            ans.push_back(matrix[end_row][i]);
        //end_col > center 防止当前圈是单列的特殊情况
        for(int i = end_row; i >= center + 1 && end_col > center; i-- )
            ans.push_back(matrix[i][center]);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0) return ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int len = row * col;
        //转圈的数目
        int circle = 0;
        //中心点(center, center)
        int center = 0;
        while( row >= 2 * circle + 1 && col >= 2 * circle + 1 ){
            draw_cycle(ans, matrix, row, col, center);
            circle++, center++;
        }
        
        return ans;
    }
};