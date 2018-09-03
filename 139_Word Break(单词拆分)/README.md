# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 139_Word Break(单词拆分)
## 问题描述、样例与输入输出

### 问题描述

给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
__说明__：

1. 拆分时可以重复使用字典中的单词。
2. 你可以假设字典中没有重复的单词。 

### 问题样例

	示例1:
	输入: 
	s = "leetcode", wordDict = ["leet", "code"]
	输出: 
	true
	解释: 
	返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
	
	示例2:
	输入: 
	s = "applepenapple", wordDict = ["apple", "pen"]
	输出: 
	true
	解释: 
	返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
    注意你可以重复使用字典中的单词。
	
	输入: 
	s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
	输出: 
	false

### 函数输入与输出

* 输入：
	* string s: 非空字符串
	* vector<string>& wordDict：包含非空单词列表的字典 wordDict
* 输出：
	* bool：是否可以拆分为单词列表里面的组合

## 思路			
### 动态规划
	
	bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset;
        //1.先将单词列表添加集合内
        for( int i = 0; i < wordDict.size(); i++ ){
            uset.insert(wordDict[i]);
        }
		// 2.动态规划
        //dp[i]代表从s[0]...s[i]是可以拆分的
        //dp[k] = ((dp[x] && wordDict.contains(s.substr(x + 1, x - j))  x = 1....k-1) || wordDict.contains(s.substr(0, k)))
        
        int len = s.size();
        vector<int> dp(len , 0);
        for( int i = 0; i < len; i++ ){
            //cout << s.substr(0, i + 1) << endl;
            if(uset.count(s.substr(0, i + 1)) > 0){
                dp[i] = 1;
                continue;
            }
            else{
                for( int j = 0; j < i; j++ ){
                    if(dp[j] && uset.count(s.substr(j + 1, i - j))){
                        dp[i] = 1;
                        break;
                    }
                }
            }
            //cout << dp[i] << endl;
        }
        return dp[len - 1];
    }
 
	
	
## 拓展与思考：
### 拓展
暂无。
### 思考
本题动态规划算法比较好，复杂度低，但是要是换成BFS则通不过样例了。你可以自己尝试一下。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
