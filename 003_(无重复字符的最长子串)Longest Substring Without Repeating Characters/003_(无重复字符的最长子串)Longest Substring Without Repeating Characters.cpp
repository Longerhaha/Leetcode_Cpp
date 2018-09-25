class Solution {
public:
    const int UNUSED = -1;
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(127, UNUSED);
        int len_s = s.size();
        int max_len = 0;
        // start 记录当前最长回文串的开始位置
        int start = 0;
        for( int i = 0; i < len_s; i++ ){
            //如果 s[i] 之前出现过，且出现在 start 之后则二者是一个有效的不含重复的子串
            if(dict[s[i]] >= start){
                //比较当前的无重复子串长度与 max_len 的大小，取二者的最大值
                max_len = max(max_len, i - start);
                //从 dict[s[i]] 下一个位置的字符开始算
                start = dict[s[i]] + 1;
            }
            dict[s[i]] = i;
        }
        return max(max_len, len_s - start);
    }
};