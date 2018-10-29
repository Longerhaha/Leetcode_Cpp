class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        if(m == 0 || n == 0) return 0;
        else if(m == 1) return accumulate(A[0].begin(), A[0].end(), 0);
        else if(n == 1){
            int sum = 0;
            for( int i = 0; i < m; i++ ) sum += A[i][0];
            return sum;
        }
        
        //二维 dp 一维化，节省内存
        vector<int> dp(n, 0);
        vector<int> pre_row_dp(dp);
        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < n; j++ ){
                if(j == 0) dp[j] = min(pre_row_dp[j], pre_row_dp[j + 1]) + A[i][j];
                else if(j == n - 1) dp[j] = min(pre_row_dp[j - 1], pre_row_dp[j]) + A[i][j];
                else dp[j] = min(pre_row_dp[j - 1], min(pre_row_dp[j], pre_row_dp[j + 1])) + A[i][j];
            }
            pre_row_dp = dp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};