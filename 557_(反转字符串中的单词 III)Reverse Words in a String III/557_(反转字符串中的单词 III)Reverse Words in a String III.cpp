class Solution {
public:
    string reverseWords(string s) {
        s += ' ';
        int len = s.size();
        int start = 0;
        for( int i = 0; i < len; i++ ){
            if(s[i] == ' '){
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        s.pop_back();
        return s;
    }
};