class Solution {
public:
    //利用堆栈与动态规划都可以做
    //这里写利用动态规划的做法
    int longestValidParentheses(string s) {
        // dp[i] 代表最长有效括号包含 s[i - 1] 的长度
        int len_s = s.size();
        vector<int> dp(len_s + 1, 0);
        dp[len_s] = 0;
        int lVP_len = 0;
        for( int i = 1; i < len_s + 1; i++ ){
            if(s[i - 1] == '(') continue;
            else{
                int left = i - 1 - 1 - dp[i - 1];
                if(left >= 0 && s[left] == '(') dp[i] = dp[i - 1] + 2 + dp[left];
            }
            lVP_len = max(lVP_len, dp[i]);
        }
        return lVP_len;
    }
};