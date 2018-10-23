# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 058_(最后一个单词的长度)Length of Last Word
## 问题描述、输入输出与样例

### 问题描述

给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

__说明__：一个单词是指由字母组成，但不包含任何空格的字符串。

### 函数输入与输出

* 输入：
	* string s：仅包含大小写字母和空格 ' ' 的字符串 s
* 输出：
	* int：最后一个单词的长度
	
### 问题样例

#### 示例1

输入: "Hello World"

输出: 5
	
	
## 思路描述与代码	
### 思路描述（常规法） 
对非 ' ' 字符进行计数，计数值为 cnt_last_word。

遇见 ' ' 字符后跳跃连续的 ' ' 字符，如果此时跳到字符串最后一个位置，说明其后无单词，最后一个单词的长度即为前一个单词的长度为 cnt_last_word， 否则 cnt_last_word 清零，重新计数。

### 代码
```cpp
int lengthOfLastWord(string s) {
	int s_len = s.size();
	int cnt_last_word = 0;
	int i = 0;
	while( i < s_len ){
		if(s[i] == ' ') {
			//跳过重复的 ' '
			while( i + 1 < s_len && s[i + 1] == ' ') i++;
			//如果最后一个也是 ' ',返回连续的 '' 前的单词的长度
			if(i == s_len - 1) return cnt_last_word;
			else cnt_last_word = 0;  
		}
		//否则加1
		else cnt_last_word++;
		i++;
	}
	return cnt_last_word;
}
```
## 思考与拓展
### 思考
本题需要考虑 ' ' 后无单词的情况。
### 拓展
暂无想法。

# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
