# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 127_(单词接龙)Word Ladder
## 问题描述、样例与输入输出

### 问题描述

给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

1. 每次转换只能改变一个字母。
2. 转换过程中的中间单词必须是字典中的单词。

__说明__：

* 如果不存在这样的转换序列，返回 0。
* 所有单词具有相同的长度。
* 所有单词只由小写字母组成。
* 字典中不存在重复的单词。
* 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

### 问题样例

	示例1:
	输入: 
	beginWord = "hit",
	endWord = "cog",
	wordList = ["hot","dot","dog","lot","log","cog"]
	输出: 
	5
	解释：
	一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
    返回它的长度 5。
	
	示例2:
	输入: 
	beginWord = "hit"
	endWord = "cog"
	wordList = ["hot","dot","dog","lot","log"]
	输出: 
	0
	解释: 
	endWord "cog" 不在字典中，所以无法进行转换。
	

### 函数输入与输出

* 输入：
	* string beginWord：开始词
	* string endWord：结束词
	* vector<string>& wordList：单词列表的引用
* 输出：
	* int：逆波兰表达式求值的结果

## 思路	
### 哈希表记录深度、集合记录字典法

	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //键是字符串，键值是深度
        unordered_map<string, int> umap;
        //存储单词的字典
        unordered_set<string> dict;
        for( auto x : wordList)
            dict.insert(x);
        //去除字典中的 beginWord
        dict.erase(beginWord);
        
        //先把 beginWord 加入队列
        umap[beginWord] = 1;
        queue<string> q;
        q.push(beginWord);
        //BFS
        while( !q.empty() ){
            //先弹出队列中一个元素
            string str = q.front();
            q.pop();
            //如果与endWord相等
            if(endWord.compare(str) == 0)
                return umap[str];
            
            int depth = umap[str];
            for( int i = 0; i < str.size(); i++ ){
                //记录i位置的字符
                char old_str = str[i];
                //遍历该位置其他可能的字符
                for( char x = 'a' ; x <= 'z'; x++ ){
                    if(x != old_str){
                        //替换该位置的单词为x
                        str.replace(i, 1, 1, x);
                        //如果该单词在字典中，记录深度、进队并从字典中删去，防止BFS时多次遍历
                        if(dict.count(str) > 0){
                            umap[str] = depth + 1;
                            q.push(str);
                            dict.erase(str);
                        }
                    }
                }
                //恢复i位置的字符
                str[i] = old_str;
            }
        }
        return 0;
    }
		

 
## 拓展与思考：
### 拓展
如果让你返回所有可能的方案呢？
### 思考
本题，如果你在BFS中用遍历字典的方式来找相邻节点则复杂度很高，无法通过测试样例。
但是依据每个词的某个字符变化为其他小写字符，再查看变化后的单词是否在字典中这大大简化了复杂度。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
