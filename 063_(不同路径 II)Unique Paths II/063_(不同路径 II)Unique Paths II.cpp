class Solution {
public:
    //dp[i][j] 代表从左上角到网格(i + 1, j + 1)的路径数目
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //边界
        dp[0][0] = !obstacleGrid[0][0];
        for( int i = 1; i < m; i++ ) dp[i][0] = dp[i - 1][0] && !obstacleGrid[i][0];
        for( int j = 1; j < n; j++ ) dp[0][j] = dp[0][j - 1] && !obstacleGrid[0][j];
        //迭代
        for( int i = 1; i < m; i++ ){
            for(int j = 1; j < n; j++ ){
                //上方往下的路和左方往右的路
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};