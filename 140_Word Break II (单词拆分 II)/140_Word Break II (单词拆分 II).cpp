class Solution {
public:
    /* 会超时
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> possible_break;
        unordered_set<string> uset;
        //1.先将单词列表添加集合内
        for( int i = 0; i < wordDict.size(); i++ ){
            uset.insert(wordDict[i]);
        }
        vector<string> path;
        wordBreak_dfs(s, s.size(), path, possible_break, uset);
        return possible_break;
    }
    
    
    void wordBreak_dfs(string s, int len, vector<string> &path, vector<string> &possible_break, unordered_set<string> &uset){
        if(len == 0){
            string str_path;
            str_path += path[0];
            for( int i = 1; i < path.size(); i++ )
                (str_path += ' ') += path[i];
            possible_break.push_back(str_path);
            return ;
        }
        for( int i = 0 ; i < len; i++ ){
            if(uset.count(s.substr(0, i + 1)) > 0){
                path.push_back(s.substr(0, i + 1));
                wordBreak_dfs(s.substr(i + 1, len - i - 1), len - i - 1, path, possible_break, uset);
                path.pop_back();
            }
        }
    }*/
    

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset;
        //1.先将单词列表添加集合内
        for( int i = 0; i < wordDict.size(); i++ ){
            uset.insert(wordDict[i]);
        }
        return wordBreak_dp(s, uset);
    }
    
    //---------------------
    // Dynamic Programming
    //---------------------
    //
    //  Define substring[i, j] is the sub string from i to j.
    //
    //       (substring[i,j] == word) :   result[i] = substring[i,j] + {result[j]}
    //
    //      So, it's better to evaluate it backword. 
    //
    //  For example:
    //
    //    s = "catsanddog",
    //    dict = ["cat", "cats", "and", "sand", "dog"].
    //  
    //       0  c  "cat"  -- word[0,2] + {result[3]}  ==> "cat sand dog"
    //             "cats" -- word[0,3] + {result[4]}  ==> "cats and dog" 
    //       1  a  ""
    //       2  t  ""
    //       3  s  "sand" --  word[3,6] + {result[7]} ==> "sand dog"
    //       4  a  "and"  --  word[4,6] + {result[7]} ==> "and dog"
    //       5  n  ""
    //       6  d  ""
    //       7  d  "dog"
    //       8  o  ""
    //       9  g  ""

    vector<string> wordBreak_dp(string s, unordered_set<string> &uset) {
        vector< vector<string> > result(s.size());

        for(int i=s.size()-1; i>=0; i--) {
            vector<string> v;
            result[i] = v;
            for(int j=i+1; j<=s.size(); j++) {
                string word = s.substr(i, j-i);
                if (uset.find(word) != uset.end()){
                    if (j==s.size()){
                        result[i].push_back(word);
                    }else{
                        for(int k=0; k<result[j].size(); k++){
                            result[i].push_back(word + " " + result[j][k]);
                        }
                    }
                }
            } 
        }
        return result[0];
    }

    
};