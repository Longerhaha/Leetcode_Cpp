class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len_s = s.size();
        int len_t = t.size();
        //边界情况
        if(len_s > len_t) return false;
        else if(len_s == 0) return true;
        
        //遍历t
        int i = 0, j = 0;
        for( j = 0; j < len_t; j++ ){
            //如果当前字符相等，查找 s 的下一个字符是否在 t 中
            if(s[i] == t[j]){
                if(i == len_s - 1) return true;
                else i++;
            }
        }
        return false;
    }
};