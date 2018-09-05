# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 140_Word Break II (单词拆分 II)
## 问题描述、样例与输入输出

### 问题描述

给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来
构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

__说明__：

1. 拆分时可以重复使用字典中的单词。
2. 你可以假设字典中没有重复的单词。 

### 问题样例

	示例1:
	输入: 
	s = "catsanddog"
	wordDict = ["cat", "cats", "and", "sand", "dog"]
	输出: 
	[
	  "cats and dog",
	  "cat sand dog"
	]

	
	示例2:
	输入: 
	s = "pineapplepenapple"
	wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
	输出: 
	[
	  "pine apple pen apple",
	  "pineapple pen apple",
	  "pine applepen apple"
	]
	解释: 
	注意你可以重复使用字典中的单词。
	
	
	示例3:
	输入: 
	s = "catsandog"
	wordDict = ["cats", "dog", "sand", "and", "cat"]
	输出: 
	[]

### 函数输入与输出

* 输入：
	* string s: 非空字符串
	* vector<string>& wordDict：包含非空单词列表的字典 wordDict
* 输出：
	* vector<string>：拆分的字符串方案列表

## 思路	
### [带路径记忆的DFS](https://github.com/haoel/leetcode/blob/master/algorithms/cpp/wordBreak/wordBreak.II.cpp)

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
		
### [带路径记忆的DFS的变形：动态规划](https://github.com/haoel/leetcode/blob/master/algorithms/cpp/wordBreak/wordBreak.II.cpp)
	
	//基于动态规划的方法其实就是上述带有记录路径功能的DFS的变身而已，在这里就不过多详细
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
 
	
	
## 拓展与思考：
### 拓展
如果字典中有重复的单词且不能使用重复的单词呢？
### 思考
本题还是非常有意思的，常规的DFS会超时。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
