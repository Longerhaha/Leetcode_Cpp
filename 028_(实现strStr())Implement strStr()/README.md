# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 028_(实现strStr())Implement strStr()
## 问题描述、输入输出与样例

### 问题描述

实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

__说明__:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
### 函数输入与输出

* 输入：
	* string haystack：匹配字符串 haystack
	* string needle：模板字符串 needle
* 输出：
	* int：needle 字符串在 haystack 字符串出现的第一个位置
	
### 问题样例

#### 示例1

输入: haystack = "hello", needle = "ll"

输出: 2

#### 示例2

输入: haystack = "aaaaa", needle = "bba"

输出: -1
	
	
## 思路描述与代码	
### 思路描述（KMP算法）
可以参考[KMP算法最浅显理解——一看就明白](https://blog.csdn.net/starstar1992/article/details/54913261/)和[从头到尾彻底理解KMP（2014年8月22日版）](https://blog.csdn.net/v_JULY_v/article/details/7041827)

### 代码
```cpp
//KMP算法
vector<int> get_next(string pattern){
	int pattern_len = pattern.size();
	// next[j] 的意义是 pattern[j] 失配后跳到 pattern[next[j]] 索引继续匹配
	vector<int> next(pattern_len, 0);
	next[0] = -1;
	int k = -1;
	for( int i = 1; i < pattern_len; i++ ){
		if(k == -1 || pattern[k] == pattern[i - 1]){
			next[i] = ++k;
			//调整 k
			while( k != -1 && pattern[k] != pattern[i]) k = next[k];
		}
		else{
			while( k != -1 && pattern[k] != pattern[i - 1]) k = next[k];
			next[i] = k;
		}  
		
	}
	return next;
}

int strStr(string haystack, string needle) {
	if(needle.size() == 0) return 0;
	
	vector<int> next = get_next(needle);
	
	for( int i = 0; i < next.size(); i++ )
		cout << next[i] << " ";
	cout << endl;
	
	int len_h = haystack.size();
	int len_n = needle.size();
	int i = 0;
	int j = 0;
	while( i < len_h && j < len_n ){
		// j == -1 说明不匹配
		if(j == -1 || haystack[i] == needle[j]){
			i++, j++;
		}
		else j = next[j];
	}	
	if(j == len_n) return i - j;
	else return -1;
}
```
## 思考与拓展
### 思考
KMP 算法其实也不难理解，想明白了 next 矩阵由何而来是关键。
### 拓展
可以了解下 BM、SUNDAY算法。


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
