class Solution {
public:
    /*按如下圈的方式添加数据
              （上行）
             ---------|
    left_col |        | right_col
             |---------
              （下行）
    比如：
    [
     [ 1, 2, 3 ],
     [ 4, 5, 6 ],
     [ 7, 8, 9 ]
    ]
    第一圈添加：上行1,2 右列3,6 下行9,8 左列7,4 第二圈 5
    */
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0) return ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int len = row * col;
        //转圈的数目
        int circle = 1;
        //每圈开始的中心位置
        int r0 = 0, c0 = 0;
        int cnt = 0;
        while( cnt < len ){
            //每次转圈上行和下行走动的步数
            int row_size = col + 1 - circle * 2;
            //每次转圈左列和右列走动的步数
            int col_size = row + 1 - circle * 2;
            //只剩一个中心点
            if(row_size == 0 && col_size == 0){
                ans.push_back(matrix[r0][c0]);
                cnt++;
            }
            else{
                //上行
                for( int i = 0; i < row_size && cnt < len; i++ )
                    cnt++, ans.push_back(matrix[r0][c0 + i]);
                //右列
                for( int j = 0; j < col_size && cnt < len; j++ )
                    cnt++, ans.push_back(matrix[r0 + j][c0 + row_size]);
                //下行
                for( int i = row_size; i > 0 && cnt < len; i-- )
                    cnt++, ans.push_back(matrix[r0 + col_size][c0 + i]);
                //左列
                for( int j = col_size; j > 0 && cnt < len; j-- )
                    cnt++, ans.push_back(matrix[r0 + j][c0]);
                r0++, c0++, circle++;
            } 
        }
        return ans;
    }
};