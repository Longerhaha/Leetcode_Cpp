class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> dict(26, 0);
        int len = s.size();
        for( int i = 0; i < len; i++ ) dict[s[i] - 'a'] += 1;
        for( int i = 0; i < len; i++ ){
            if(dict[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};