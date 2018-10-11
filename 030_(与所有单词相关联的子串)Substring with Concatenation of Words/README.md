# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 030_(与所有单词相关联的子串)Substring with Concatenation of Words
## 问题描述、输入输出与样例

### 问题描述

给定一个字符串 s 和一些长度相同的单词 words。在 s 中找出可以恰好串联 words 中所有单词的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

### 函数输入与输出

* 输入：
	* string s： 给定的字符串 s
	* vector<string>& words：长度相同的单词 words
* 输出：
	* vector<int>：可以恰好串联 words 中所有单词的子串的起始位置的列表
	
### 问题样例

#### 示例1

输入:s = "barfoothefoobarman", words = ["foo","bar"]

输出: [0,9]

解释: 从索引 0 和 9 开始的子串分别是 "barfoor" 和 "foobar" 。输出的顺序不重要, [9,0] 也是有效答案。
	
#### 示例2

输入: s = "wordgoodstudentgoodword", words = ["word","student"]
输出: []
	
## 思路描述与代码	
### 思路描述（哈希表+滑动搜索窗）

1.现将单词列表保存到 word_dict 哈希表中；

2.words 列表的每个单词长度 word_len 都相同，可以利用这个性质对程序做个简化。

比如 s = "barfoothefoobarman", words = ["foo","bar"]，我们搜索：
* 以0、3、6、9、12、15为下标且长度为3单词列表
* 以1、4、7、10、13、16为下标且长度为3单词列表
* 以2、5、8、11、14、17为下标且长度为3单词列表

对每个单词列表进行滑窗搜索，并使用哈希表 match_dict 记录匹配的窗，cnt 记录匹配的单词数目，同时 start 记录匹配窗的起始位置：
* if(搜索的当前单词 cur_str 不在 word_dict 内)，则 start = start + word_len，cnt 清零， match_dict 清零；
* else:
	* 先记录 cur_str 到 match_dict中，同时 cnt++
	* if(cur_str 在 word_dict 出现的次数 大于等于 cur_str 在 match_dict 出现的次数)，则判断窗口的单词个数 cnt 是否与 words_len 相同（words 列表的列表大小）
		* 如果相同，则记录 start 位置到返回列表中，同时窗口向右滑动一个单词，即 start += words_len、cnt--、--match_dict[s.substr(start, len_word)];
		* 如果不同，则维持当前搜索窗口;
	* else 则说明当前窗口需要调整了，调整就是从左往右调整，直到 cur_str 在 word_dict 出现的次数 等于 cur_str 在 match_dict 出现的次数;



### 代码
```cpp
//滑窗搜索
vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> res;
	int len_s = s.size();
	int len_words = words.size();
	if(len_s == 0 || len_words == 0) return res;
	int len_word = words[0].size();
	
	//添加字典
	unordered_map<string, int> word_dict;
	for( auto word : words ) ++word_dict[word];
	//由于单词 words 长度固定，可以把 s 分成 len_word 个部分
	//每个部分间隔 len_word 去搜索
	//比如 abcedfsadsd
	//分成 a  e  s  s
	//      b  d  a  d
	//       c  f  d
	for( int i = 0; i < len_word; i++ ){
		unordered_map<string, int> match_dict;
		int start = i;
		int cnt = 0;
		for( int j = i; j <= len_s - len_word; j += len_word ){
			string cur_str = s.substr(j, len_word);
			if(word_dict.count(cur_str) > 0){
				++match_dict[cur_str];
				cnt++;
				if(match_dict[cur_str] <= word_dict[cur_str]){
					if(cnt == len_words){
						res.push_back(start);
						cnt--;
						//滑窗搜索
						--match_dict[s.substr(start, len_word)];
						start += len_word;
					}
				}
				else{  
					//窗口调整为最大匹配的窗
					while(match_dict[cur_str] > word_dict[cur_str]){
						--match_dict[s.substr(start, len_word)];
						--cnt;
						start += len_word;
					}
				}
			}
			else{
				start = j + len_word;
				cnt = 0;
				match_dict.clear();
			}
		}
	}
	return res;
}
```
## 思考与拓展
### 思考
本题的单词列表长度相同才可以简化了算法，单词列表如果不相同则会更加复杂。
### 拓展
如果单词列表长度不相同呢？


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
