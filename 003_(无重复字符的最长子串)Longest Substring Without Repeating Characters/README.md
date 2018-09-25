# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 003_(无重复字符的最长子串)Longest Substring Without Repeating Characters
## 问题描述、输入输出与样例

### 问题描述

给定一个字符串，找出不含有重复字符的最长子串的长度。

### 函数输入与输出

* 输入：
	* string s：给定的字符串 s
* 输出：
	* int：不含有重复字符的最长子串的长度
	
### 问题样例

#### 示例1

	输入: "abcabcbb"
	输出: 3 
	解释: 无重复字符的最长子串是 "abc"，其长度为 3。
	
#### 示例2

	输入: "abcabcbb"
	输出: 3 
	解释: 无重复字符的最长子串是 "abc"，其长度为 3。
	
#### 示例3

	输入: "pwwkew"
	输出: 3
	解释: 无重复字符的最长子串是 "wke"，其长度为 3。
		请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。
	
	
## 思路描述与代码	
### 思路描述（字典法）

使用 dict[s[i]] 记录字符 s[i] 出现的位置

start 记录当前搜索回文串的开始位置

max_len 记录最大的回文串长度

for i = 0 : len_s - 1
	如果 s[i]之前出现过，记录当前的回文串长度，并与 max_len 比较，同时 start = dict[s[i]] + 1
	记录 s[i]出现的位置

返回 max_len 与 len_s - start 的最大值

### 代码
	
	const int UNUSED = -1;
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(127, UNUSED);
        int len_s = s.size();
        int max_len = 0;
        // start 记录当前最长回文串的开始位置
        int start = 0;
        for( int i = 0; i < len_s; i++ ){
            //如果 s[i] 之前出现过，且出现在 start 之后则二者是一个有效的不含重复的子串
            if(dict[s[i]] >= start){
                //比较当前的无重复子串长度与 max_len 的大小，取二者的最大值
                max_len = max(max_len, i - start);
                //从 dict[s[i]] 下一个位置的字符开始算
                start = dict[s[i]] + 1;
            }
            dict[s[i]] = i;
        }
        return max(max_len, len_s - start);
    }
 
 
## 拓展与思考：
### 拓展
暂无想法。
### 思考
本题需要使用字典去记录位置，简化时间复杂度。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
