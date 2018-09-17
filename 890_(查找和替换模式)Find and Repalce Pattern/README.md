# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 890_(查找和替换模式)Find and Repalce Pattern
## 问题描述、输入输出与样例

### 问题描述

你有一个单词列表 words 和一个模式  pattern，你想知道 words 中的哪些单词与模式匹配。

如果存在字母的排列 p ，使得将模式中的每个字母 x 替换为 p(x) 之后，我们就得到了所需的单词，那么单词与模式是匹配的。

（回想一下，字母的排列是从字母到字母的双射：每个字母映射到另一个字母，没有两个字母映射到同一个字母。）

返回 words 中与给定模式匹配的单词列表。

你可以按任何顺序返回答案。

### 函数输入与输出

* 输入：
	* vector<string>& words：给定的单词列表
	* string pattern：模式单词
* 输出：
	* vector<string>：与给定模式匹配的单词列表
	
### 问题样例

	示例1:
	输入: 
	words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
	  
	输出: 
	["mee","aqq"]
	
	解释：
	"mee" 与模式匹配，因为存在排列 {a -> m, b -> e, ...}。
	"ccc" 与模式不匹配，因为 {a -> c, b -> c, ...} 不是排列。
	因为 a 和 b 映射到同一个字母。
	
## 思路描述与代码	
### 思路描述（双字典法）

对每个属于单词列表words的单词word，使用dict1 记录 word 中的字符 word[i] 对 pattern 字符 pattern[i] 的映射

使用dict2 记录 pattern 中的字符 pattern[i] 对 word 字符 word[i] 的映射

遍历word的所有字符 word[i]

* 如果 word[i] 未被映射
	* 如果 pattern[i] 未被映射，双方记录映射关系
	* 如果 pattern[i] 已被映射，确认 pattern[i] 映射的对象是不是 word[i]，如果不是则失败
* 如果 word[i] 已被映射 且 映射对象不是 pattern[i]，则失败

如果成功，记录word

### 代码
	
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
 
 
## 拓展与思考：
### 拓展
暂无想法。

### 思考
本题需要使用两个字典记录映射关系，不然可能导致一对多或者多对一情况。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
