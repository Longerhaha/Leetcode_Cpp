# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 032_(最长有效括号)Longest Valid Parentheses
## 问题描述、输入输出与样例

### 问题描述

给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

### 函数输入与输出

* 输入：
	* string s：给定的字符串 s
* 输出：
	* int：最长的包含有效括号的子串的长度
	
### 问题样例

#### 示例1

输入: "(()"

输出: 2

解释: 最长有效括号子串为 "()"：
	
	
## 思路描述与代码	
### 思路描述（方法）
本题可以使用动态规划和堆栈法来解。基于堆栈法较为简单，下面描述下动态规划方法的思路：

dp[i] 代表最长有效括号包含 s[i - 1] 的长度并初始化为 0 ，lVP_len 记录最长的包含有效括号的子串的长度。

```cpp
for( int i = 1; i < len_s + 1; i++ ){
	if(s[i - 1] == '(') continue; //左括号则其肯定不是最长的包含有效括号的子串，由于初始化为 0 ，所以不需要操作了，直接跳过
	else{
		int left = i - 1 - 1 - dp[i - 1];
		//如果与 s[left] 匹配，则加2且加上 dp[left]
		if(left >= 0 && s[left] == '(') dp[i] = dp[i - 1] + 2 + dp[left];
	}
	lVP_len = max(lVP_len, dp[i]);
}
```

### 代码
```cpp
int longestValidParentheses(string s) {
	// dp[i] 代表最长有效括号包含 s[i - 1] 的长度
	int len_s = s.size();
	vector<int> dp(len_s + 1, 0);
	dp[len_s] = 0;
	int lVP_len = 0;
	for( int i = 1; i < len_s + 1; i++ ){
		if(s[i - 1] == '(') continue;
		else{
			int left = i - 1 - 1 - dp[i - 1];
			if(left >= 0 && s[left] == '(') dp[i] = dp[i - 1] + 2 + dp[left];
		}
		lVP_len = max(lVP_len, dp[i]);
	}
	return lVP_len;
}
```
## 思考与拓展
### 思考
动态规划法重要的是写上递推公式，其他问题一般不大。
### 拓展
如果让你使用堆栈法呢？


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
