class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string s_convert;
        for( int i = 0; i < numRows; i++ ){
            if(i == 0 || i == numRows - 1){
                int j = i;
                while( j < s.size() ){
                    s_convert.push_back(s[j]);
                    j += (2 * numRows - 2);
                }
            }
            else{
                int idx_1 = i, idx_2 = 2 * numRows - i - 2;
                while( idx_1 < s.size() || idx_2 < s.size()){
                    if(idx_1 < s.size()) s_convert.push_back(s[idx_1]);
                    if(idx_2 < s.size()) s_convert.push_back(s[idx_2]);
                    idx_1 += (2 * numRows - 2);
                    idx_2 += (2 * numRows - 2);
                }
            }
        }
        return s_convert;
    }
};