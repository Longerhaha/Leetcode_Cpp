class Solution {
public:
    bool bound(const vector<int> &pos, const int check_idx){
        for( int i = 0; i < check_idx; i++ ){
            if(pos[i] == pos[check_idx] || abs(i - check_idx) == abs(pos[i] - pos[check_idx])) return false; 
        }
        return true;
    }
    
    void solveNQueens_backtrack(int &solver_num, vector<int> &pos, const int size, int start){
        if(start == size){
            solver_num++;
            return ;
        }
        for( int i = 0; i < size; i++ ){
            pos[start] = i;
            if(bound(pos, start)) solveNQueens_backtrack(solver_num, pos, size, start + 1);
        }
    }
    
    int totalNQueens(int n) {
        int solver_num = 0;
        vector<int> pos(n, 0);
        solveNQueens_backtrack(solver_num, pos, n, 0);
        return solver_num;
    }
    
};