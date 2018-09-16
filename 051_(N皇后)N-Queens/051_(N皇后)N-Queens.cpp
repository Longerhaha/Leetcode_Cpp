class Solution {
public:
    //界限函数
    bool Bound(vector<int> &pos, int idx){
        for( int i = 0; i < idx ; i++ ){
            //如果不在同一列或者对角线
            if(pos[idx] == pos[i] || abs(pos[idx] - pos[i]) == abs(idx - i)) return false;
        }
        return true;
    }
    //解空间树是子集树的的回溯
    void solveNQueens_backtrack(vector<vector<string>> &ans, vector<int> &pos, int n, int idx){
        if(idx == n){
            //根据pos生成方案
            vector<string> scheme;
            for( int i = 0; i < n; i++ ){
                string row_str;
                row_str.insert(0, pos[i], '.');
                row_str.insert(pos[i], 1, 'Q');
                row_str.insert(pos[i] + 1, n - pos[i] - 1, '.');
                scheme.push_back(row_str);
            }
            ans.push_back(scheme);
            return ;
        }
        //子集树 
        for( int i = 0; i < n; i++ ){
            pos[idx] = i;
            if(Bound(pos, idx)) solveNQueens_backtrack(ans, pos, n, idx + 1);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> pos(n);
        solveNQueens_backtrack(ans, pos, n, 0);
        return ans;
    }
};