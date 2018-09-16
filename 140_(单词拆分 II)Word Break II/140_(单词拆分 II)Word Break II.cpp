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
    
    
    //参考：https://github.com/haoel/leetcode/blob/master/algorithms/cpp/wordBreak/wordBreak.II.cpp
    
    //添加一个记录s路径的哈希表，以空间换时间，否则递归会超时
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset;
        //1.先将单词列表添加集合内
        for( int i = 0; i < wordDict.size(); i++ ){
            uset.insert(wordDict[i]);
        }
        //2.用来记录s的DFS路径，牺牲空间换时间
        unordered_map<string, vector<string>> ump;
        //3.返回带记录路径功能的DFS对s遍历的结果
        return wordBreak_dfs_rcrd_path(s, uset, ump);
    }
    
    //带记录路径功能的DFS
    vector<string> wordBreak_dfs_rcrd_path(string s, unordered_set<string> &uset, unordered_map<string, vector<string>> &ump){
        //如果s的方案存在,直接返回方案
        if(ump.find(s) != ump.end())
            return ump[s];
        
        //如果不存在则搜索
        vector<string> break_s;
        for( int i = 0 ; i < s.size(); i++ ){
            string sub = s.substr(0, i + 1);
            //如果字典中存在sub则需要深搜
            if(uset.count() > 0){
                //如果搜到尾巴了就可以返回了
                if(i == s.size() - 1){
                    break_s.push_back(sub);
                    break;
                }
                //否则搜其后的字符串的结果并与sub合成路径记录在ump中
                else{
                    vector<string> later = wordBreak_dfs_rcrd_path(s.substr(i + 1, s.size() - i - 1), uset, ump);
                    for( int j = 0; j < later.size(); j++ ){
                        break_s.push_back(sub + " " + later[j]);
                    }
                }
            }
        }
        //记录路径
        ump[s] = break_s;
        return ump[s];
    }
    
    
    

    /* 基于动态规划的方法其实就是上述带有记录路径功能的DFS的变身而已，在这里就不过多详细
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

    */
};