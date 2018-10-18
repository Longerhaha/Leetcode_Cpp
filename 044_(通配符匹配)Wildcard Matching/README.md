# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 044_(通配符匹配)Wildcard Matching
## 问题描述、输入输出与样例

### 问题描述

给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

* '?' 可以匹配任何单个字符。
* '*' 可以匹配任意字符串（包括空字符串）。

两个字符串完全匹配才算匹配成功。

说明:

* s 可能为空，且只包含从 a-z 的小写字母。
* p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。

### 函数输入与输出

* 输入：
	* string s：待匹配字符串 s
	* string p：字符模式串 p
* 输出：
	* bool：是否匹配
	
### 问题样例

#### 示例1

输入:

	s = "aa"
	p = "a"

输出: false

解释: "a" 无法匹配 "aa" 整个字符串。

#### 示例2

输入:

	s = "aa"
	p = "*"

输出: true

解释: '*' 可以匹配任意字符串。

#### 示例3

输入:

	s = "cb"
	p = "?a"

输出: false

解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。

#### 示例4

输入:

	s = "adceb"
	p = "*a*b"

输出: true

解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".

#### 示例5

输入:

	s = "acdcb"
	p = "a*c?b"

输入: false。
	
	
## 思路描述与代码	
### 思路描述（动态规划法）
dp[i][j] 代表 s[0,1,...,i-1] 与 p[0,1,2,...j-1] 是否匹配

由通配符的意义可知 dp 递推表示式如下：
```cpp
			dp[i - 1][j - 1],              if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
dp[i][j] =  dp[i][j - 1] || dp[i - 1][j],  if(p[j - 1] == '*')
			false,                         else			
```
### 代码
```cpp
//dp[i][j] 代表 s[0,1,...,i-1] 与 p[0,1,2,...j-1] 是否匹配
bool isMatch(string s, string p) {
	int len_s = s.size();
	int len_p = p.size();
	vector<vector<bool> >dp(len_s + 1, vector<bool>(len_p + 1));
	//边界初始化
	dp[0][0] = true;
	for( int i = 1; i < len_s + 1; i++ ) dp[i][0] = false;
	for( int j = 1; j < len_p + 1; j++ ) dp[0][j] = p[j - 1] == '*' ? dp[0][j - 1] : false;
	for( int i = 1; i < len_s + 1; i++ ){
		for( int j = 1; j < len_p + 1; j++ ){
			dp[i][j] = false;
		}
	}
	
	//扫描
	for( int i = 1; i < len_s + 1; i++ ){
		for( int j = 1; j < len_p + 1; j++ ){
			if(s[i - 1] == p[j - 1] || p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
			else if(p[j - 1] == '*') dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
			else dp[i][j] = false;
		}
	}
	return dp[len_s][len_p];
}
```
## 思考与拓展
### 思考
利用动态规划解这道题相对较为简单。
### 拓展
回忆一下[10.正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/)


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
