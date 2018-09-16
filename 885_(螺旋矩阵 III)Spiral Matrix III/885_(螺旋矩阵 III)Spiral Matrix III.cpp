class Solution {
public:
    //扩张的方式(比如size为2)
    //分四个方向扩张
    //                | --- ---
    //                |   c   |
    //                 --- ---|
    //
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        ans.push_back({r0, c0});
        //扩张的步长
        int step = 2;
        int col, row;
        while(ans.size() < R * C){
            //右反纵向扩张
            col = c0 + 1;
            for( row = r0; row < r0 + step; row++ ){
                if(row >= 0 && row < R && col >= 0 && col < C){
                    ans.push_back({row, col});
                }
            }
            //下反横向扩张
            row = r0 + step - 1;
            for( col = c0; col > c0 - step; col-- ){
                if(row >= 0 && row < R && col >= 0 && col < C){
                    ans.push_back({row, col});
                }
            }
            //左反纵向扩张
            col = c0 - step + 1;
            for( row = r0 + step - 2; row >= r0 - 1; row-- ){
                if(row >= 0 && row < R && col >= 0 && col < C){
                    ans.push_back({row, col});
                }
            }
            //上横向扩张
            row = r0 - 1;
            for( col = c0 - step + 2; col <= c0 + 1; col++ ){
                if(row >= 0 && row < R && col >= 0 && col < C){
                    ans.push_back({row, col});
                }
            }
            //步长加2，并移动中心点，为下次扩张做好准备
            step += 2;
            r0 = r0 - 1;
            c0 = c0 + 1;
            //cout << ans.size() << endl;
        }
        
        return ans;
    }
};