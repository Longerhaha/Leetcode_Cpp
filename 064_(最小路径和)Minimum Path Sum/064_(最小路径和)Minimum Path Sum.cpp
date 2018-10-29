class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //动态规划
        //dp[i][j] 代表从左上角(1, 1)到网格(i + 1, j + 1)的最小路径和
        int m = grid.size();
        int n =  grid[0].size();
        vector<int> dp(n, 0);
        //边界初始化
        dp[0] = grid[0][0];
        for( int j = 1; j < n; j++) dp[j] = dp[j - 1] + grid[0][j];
        //二维DP一维化的关键是存储上一行的DP
        vector<int> pre_row_dp(dp);
        for( int i = 1; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                if(j == 0) dp[j] = pre_row_dp[j] + grid[i][j];
                else dp[j] = min(dp[j - 1], pre_row_dp[j]) + grid[i][j];
            }
            pre_row_dp = dp;
        }
        return dp[n - 1];
        
        
    }
};