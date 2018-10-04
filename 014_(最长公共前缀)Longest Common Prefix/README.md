# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 014_(最长公共前缀)Longest Common Prefix
## 问题描述、输入输出与样例

### 问题描述

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

### 函数输入与输出

* 输入：
	* vector<string>& strs：字符串列表
* 输出：
	* string：最长公共前缀（字符串）
	
### 问题样例

#### 示例1

输入: ["flower","flow","flight"]

输出: "fl"

#### 示例2
输入: ["dog","racecar","car"]

输出: ""

解释: 输入不存在公共前缀。

#### 说明
所有输入只包含小写字母 a-z 。
	
	
## 思路描述与代码	
### 思路描述（逐次比较法）
一个个的判断第一个字符串的各个字符是否在其他字符串中也有，直到出现不一样或者比较结束。

### 代码

	string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int str_size = strs.size();
        if(!str_size) return ans;
        int min_str_size = strs[0].size();
        for( int i = 0; i < str_size; i++ )
            min_str_size = min(min_str_size, (int)strs[i].size());
        
        int i = 0;
        int stop_flag = 0;
        while( !stop_flag && i < min_str_size ){
            char compare = strs[0][i];
            for( int j = 0; j < str_size; j++ ){
                if(strs[j][i] != compare){
                    stop_flag = 1;
                    break;
                }
            }
            i++;
            if(!stop_flag) ans += compare;
        }
        return ans;
    }
 
## 思考与拓展
### 思考
本题思路比较直接，也没有什么简便的其他方法。
### 拓展
如果让你找最长公共后缀呢？


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
