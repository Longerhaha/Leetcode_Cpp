class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for( auto word : words ){
            // dict1 记录 word 中的字符对 pattern 字符的映射
            // dict2 记录 pattern 中的字符对 word 字符的映射
            vector<int> dict1(127, -1);
            vector<int> dict2(127, -1);
            int word_len = word.size();
            int fail = 0;
            for( int i = 0; i < word_len; i++ ){
                // 如果 word[i] 未被映射
                // (i) 如果 pattern[i] 未被映射，双方记录映射关系
                // (ii) 如果 pattern[i] 已被映射，确认 pattern[i] 映射的对象是不是 word[i]，如果不是则失败
                if(dict1[word[i]] == -1){
                    if(dict2[pattern[i]] == -1){
                        dict1[word[i]] = pattern[i];
                        dict2[pattern[i]] = word[i];
                    }
                    else if(dict2[pattern[i]] != word[i]){
                        fail = 1;
                        break ;
                    }
                }
                // 如果 word[i] 已被映射 且 映射对象不是 pattern[i]，则失败
                else if(dict1[word[i]] != -1 && dict1[word[i]] != pattern[i]){
                    fail = 1;
                    break ;
                } 
            }
            //如果成功，记录word
            if(!fail) ans.push_back(word);
        }
        return ans;
    }
};