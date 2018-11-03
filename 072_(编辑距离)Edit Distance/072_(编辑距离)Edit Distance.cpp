class Solution {
public:
    //动态规划
    //dp[i][j] 代表 word1.substr(0, i) 转换成 word2.substr(0, j)所使用的最少操作数
    int minDistance(string word1, string word2) {
        int len_word1 = word1.size();
        int len_word2 = word2.size();
        vector<vector<int>> dp(len_word1 + 1, vector<int>(len_word2 + 1, 0));
        //边界初始化
        //word2 为空，则最小操作数为删除的次数即 word1 的长度
        for( int i = 0; i < len_word1 + 1; i++ ) dp[i][0] = i;
        //word1 为空，则最小操作数为插入的次数即 word2 的长度    
        for( int j = 0; j < len_word2 + 1; j++ ) dp[0][j] = j;
        
        for( int i = 1; i < len_word1 + 1; i++){
            for( int j = 1; j < len_word2 + 1; j++ ){
                //相等则不需要操作
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                //插入操作 dp[i][j] = dp[i][j - 1]
                //删除操作 dp[i][j] = dp[i - 1][j]
                //替换操作 dp[i][j] = dp[i - 1][j - 1]
                else dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
            }
        }
        return dp[len_word1][len_word2];
    }
};