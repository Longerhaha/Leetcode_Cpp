class Solution {
public:
    int lengthOfLastWord(string s) {
        int s_len = s.size();
        int cnt_last_word = 0;
        int i = 0;
        while( i < s_len ){
            if(s[i] == ' ') {
                //跳过重复的 ' '
                while( i + 1 < s_len && s[i + 1] == ' ') i++;
                //如果最后一个也是 ' ',返回连续的 '' 前的单词的长度
                if(i == s_len - 1) return cnt_last_word;
                else cnt_last_word = 0;  
            }
            //否则加1
            else cnt_last_word++;
            i++;
        }
        return cnt_last_word;
    }
};