class Solution {
public:
    //dp[i][j] 代表 s[0,1,...,i-1] 与 p[0,1,2,...j-1] 是否匹配
    bool isMatch(string s, string p) {
        int len_s = s.size();
        int len_p = p.size();
        vector<vector<bool> >dp(len_s + 1, vector<bool>(len_p + 1));
        //边界初始化
        dp[0][0] = true;
        for( int i = 1; i < len_s + 1; i++ ) dp[i][0] = false;
        for( int j = 1; j < len_p + 1; j++ ) dp[0][j] = p[j - 1] == '*' ? dp[0][j - 1] : false;
        for( int i = 1; i < len_s + 1; i++ ){
            for( int j = 1; j < len_p + 1; j++ ){
                dp[i][j] = false;
            }
        }
        
        //扫描
        for( int i = 1; i < len_s + 1; i++ ){
            for( int j = 1; j < len_p + 1; j++ ){
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else if(p[j - 1] == '*') dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else dp[i][j] = false;
            }
        }
        return dp[len_s][len_p];
    }
};