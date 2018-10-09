class Solution {
public:
    //KMP算法
    vector<int> get_next(string pattern){
        int pattern_len = pattern.size();
        // next[j] 的意义是 pattern[j] 失配后跳到 pattern[next[j]] 索引继续匹配
        vector<int> next(pattern_len, 0);
        next[0] = -1;
        int k = -1;
        for( int i = 1; i < pattern_len; i++ ){
            if(k == -1 || pattern[k] == pattern[i - 1]){
                next[i] = ++k;
                //调整 k
                while( k != -1 && pattern[k] != pattern[i]) k = next[k];
            }
            else{
                while( k != -1 && pattern[k] != pattern[i - 1]) k = next[k];
                next[i] = k;
            }  
            
        }
        return next;
    }
    
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        
        vector<int> next = get_next(needle);
        
        for( int i = 0; i < next.size(); i++ )
            cout << next[i] << " ";
        cout << endl;
        
        int len_h = haystack.size();
        int len_n = needle.size();
        int i = 0;
        int j = 0;
        while( i < len_h && j < len_n ){
            // j == -1 说明不匹配
            if(j == -1 || haystack[i] == needle[j]){
                i++, j++;
            }
            else j = next[j];
        }	
        if(j == len_n) return i - j;
        else return -1;
    }
};