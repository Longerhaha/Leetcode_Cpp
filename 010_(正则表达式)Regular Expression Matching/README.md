# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 010_(正则表达式)Regular Expression Matching
## 问题描述、输入输出与样例

### 问题描述

给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。

* '.' 匹配任意单个字符。
* '*' 匹配零个或多个前面的元素。

匹配应该覆盖整个字符串 (s) ，而不是部分字符串。

说明:

* s 可能为空，且只包含从 a-z 的小写字母。
* p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

### 函数输入与输出

* 输入：
	* string s：字符串 s
	* string p：字符模式 p
* 输出：
	* bool：是否匹配
	
### 问题样例

#### 示例1

输入:

s = "aa"

p = "a"

输出: false

解释: "a" 无法匹配 "aa" 整个字符串。
	
	
#### 示例 2

输入:

s = "aa"
p = "a*"

输出: true

解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。

#### 示例 3

输入:

s = "ab"
p = ".*"

输出: true

解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。

#### 示例 4

输入:

s = "aab"
p = "c*a*b"

输出: true

解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。

#### 示例 5

输入：

s = "mississippi"
p = "mis*is*p*."

输出: false
	
## 思路描述与代码	
### 思路描述（动态规划法）
dp[i][j] 代表 s.substr(0, i) 与 p.substr(0, j)是否匹配

dp[0][0] = true同时需要主要边界(dp[x][0]和dp[0][x])处理

dp[i][j] =  dp[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1])， (p[j - 1] != '*';
		 =  dp[i][j - 2] || //0个x的情况
			(dp[i - 1][j - 2] && (p[j - 2] == '.' || p[j - 2] == s[i - 1])) ||  //1个x的情况
			(dp[i - 1][j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1]));  //2个x的情况
			
			
### 代码
	
	//动态规划
    bool isMatch(string s, string p) {
        int len_s = s.size();
        int len_p = p.size();
        //dp[i][j] 代表 s.substr(0, i) 与 p.substr(0, j)是否匹配
        bool dp[len_s + 1][len_p + 1];
        //边界处理
        dp[0][0] = true;
        for( int i = 1; i < len_s + 1; i++ ) dp[i][0] = false;
        for( int j = 1; j < len_p + 1; j++ ) dp[0][j] =  p[j - 1] == '*' ? dp[0][j - 2] : false;
        for( int i = 1; i < len_s + 1; i++ ){
            for( int j = 1; j < len_p + 1; j++ ){
                if(p[j - 1] != '*') dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1]);
                //else dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || (dp[i - 1][j] && (p[j - 2] == '.' || s[i - 1] == p[j - 2]));
                //形式x*
                //dp[i][j - 2]表示0个x的情况
                //dp[i - 1][j - 2] && (p[j - 2] == '.' || p[j - 2] == s[i - 1])表示1个x的情况
                //(dp[i - 1][j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1]))表示多个x的时候
                else dp[i][j] = dp[i][j - 2] ||
                    (dp[i - 1][j - 2] && (p[j - 2] == '.' || p[j - 2] == s[i - 1])) ||
                    (dp[i - 1][j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1]));

            }
        }
        return dp[len_s][len_p];
    }
 
 
## 思考与拓展
### 思考
正则表达式常出现在文本处理中，其算法思维很值得学习。
### 拓展
如果给你更复杂的正则表达式呢？
  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
