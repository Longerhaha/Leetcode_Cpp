class Solution {
public:
    //染色方法
    //染色选择为-1,1,0
    //0代表未染色
    //若可以找到一种染色方案使得可以染色，那么返回true，否则返回false
    bool dfs_i_scheme(vector<vector<int>>& not_allowed_group, vector<int>& color, int i){
        //遍历不可以放在一起的点
        int len = not_allowed_group[i].size();
        for( int j = 0; j < len; j++ ){
            //如果未染色则染相反的颜色,如果该方案不行则返回false
            if(!color[not_allowed_group[i][j]]){
                color[not_allowed_group[i][j]] = -color[i];
                if(!dfs_i_scheme(not_allowed_group, color, not_allowed_group[i][j])) return false;
            } 
            //如果染色了但是不符合规则照样返回false
            else if(color[not_allowed_group[i][j]] != -color[i]) return false;
        } 
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> not_allowed_group(N);
        int dislikes_len = dislikes.size();
        for( int i = 0; i < dislikes_len; i++ ) not_allowed_group[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1), not_allowed_group[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
        vector<int> color(N, 0);
        for( int i = 0; i < N; i++ ){
            //如果存在以 i 为节点的方案
            if(color[i])
                continue;
            color[i] = 1;
            //否则遍历 i 节点
            if(!dfs_i_scheme(not_allowed_group, color, i))
                return false;
        }
        return true;
    }
};