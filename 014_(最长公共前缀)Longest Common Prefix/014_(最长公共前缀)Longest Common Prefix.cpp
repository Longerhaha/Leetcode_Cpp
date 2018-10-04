class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int str_size = strs.size();
        if(!str_size) return ans;
        int min_str_size = strs[0].size();
        for( int i = 0; i < str_size; i++ )
            min_str_size = min(min_str_size, (int)strs[i].size());
        
        int i = 0;
        int stop_flag = 0;
        while( !stop_flag && i < min_str_size ){
            char compare = strs[0][i];
            for( int j = 0; j < str_size; j++ ){
                if(strs[j][i] != compare){
                    stop_flag = 1;
                    break;
                }
            }
            i++;
            if(!stop_flag) ans += compare;
        }
        return ans;
    }
};