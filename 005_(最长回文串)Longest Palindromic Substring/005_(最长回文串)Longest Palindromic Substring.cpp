class Solution {
public:
    string preProcess(string s) {
        string deal_s(s);
        deal_s.insert(0, 1, '#');
        for( int i = 1; i <= s.size(); i++)
            deal_s.insert(2*i, 1, '#');
        return deal_s;
    }
    string longestPalindrome(string s) {
        string prep_s = preProcess(s);
        int R = 0, C = 0;
        int prep_s_len = prep_s.size();
        //P[i] 代表以 prep_s[i] 为中心的最长回文串的长度
        vector<int> P(prep_s_len, 0);
        for( int i = 0; i < prep_s_len; i++ ){
            //先获得镜像的位置
            int i_mirror = 2 * C - i;
            // 1. 如果 i 在当前最大最长回文串的长度的右边界 R 内，则 P[i] = min(R - i, P[i_mirror])
            //  P[i] = min(R - i, P[i_mirror])是因为其可能跨越右边界
            // 2. 否则就先给0
            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
            //尝试扩张
            while (i - 1 - P[i] >= 0 && i + 1 + P[i] < prep_s_len && prep_s[i + 1 + P[i]] == prep_s[i - 1 - P[i]]) P[i]++;
            //如果跳出当前最长回文串的覆盖范围则更新 R 和 C
            if( i + P[i] > R){
                R = i + P[i];
                C = i;
            }
        }
        
        //遍历查找最大值
        int max_p = 0, max_p_idx = 0;
        for( int i = 0; i < prep_s_len; i++ ){
            if(P[i] > max_p) max_p_idx = i, max_p = P[i];
        }
    
        return s.substr((max_p_idx - max_p) / 2, max_p);
    }
};

