# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 072_(编辑距离)Edit Distance
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。<br>
你可以对一个单词进行如下三种操作：<br>
1. 插入一个字符
2. 删除一个字符
3. 替换一个字符
### 1.2 输入与输出
输入：<br>
* string word1: 给定的单词 word1<br>
* string word2: 给定的单词 word2<br>

输出：<br>
* int: 将 word1 转换成 word2 所使用的最少操作数<br>
### 1.3 样例
#### 1.3.1 样例1
输入: word1 = "horse", word2 = "ros"<br>
输出: 3<br>
解释: <br>
horse -> rorse (将 'h' 替换为 'r')<br>
rorse -> rose (删除 'r')<br>
rose -> ros (删除 'e')<br>
#### 1.3.2 样例2
输入: word1 = "intention", word2 = "execution"<br>
输出: 5<br>
解释: <br>
intention -> inention (删除 't')<br>
inention -> enention (将 'i' 替换为 'e')<br>
enention -> exention (将 'n' 替换为 'x')<br>
exention -> exection (将 'n' 替换为 'c')<br>
exection -> execution (插入 'u')<br>
## 2 思路描述与代码	
### 2.1 思路描述（动态规划方法）
dp[i][j] 代表 word1.substr(0, i) 转换成 word2.substr(0, j)所使用的最少操作数<br>
当word1[i] == word2[j] 时则不需要操作，此时 dp[i][j] = dp[i - 1][j - 1]<br>
当word1[i] != word2[j] 时则需要操作，此时进行的操作有如下三种可能性：<br>
* 插入操作 dp[i][j] = dp[i][j - 1]
* 删除操作 dp[i][j] = dp[i - 1][j]
* 替换操作 dp[i][j] = dp[i - 1][j - 1]

于是得到递推表达式如下<br>
dp[i][j]　＝　dp[i - 1][j - 1], if word1[i] == word2[j]<br>
　　　　＝　min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1, else
### 2.2 代码
```cpp
int minDistance(string word1, string word2) {
    int len_word1 = word1.size();
    int len_word2 = word2.size();
    vector<vector<int>> dp(len_word1 + 1, vector<int>(len_word2 + 1, 0));
    //边界初始化
    //word2 为空，则最小操作数为删除的次数即 word1 的长度
    for( int i = 0; i < len_word1 + 1; i++ ) dp[i][0] = i;
    //word1 为空，则最小操作数为插入的次数即 word2 的长度    
    for( int j = 0; j < len_word2 + 1; j++ ) dp[0][j] = j;
    
    for( int i = 1; i < len_word1 + 1; i++){
        for( int j = 1; j < len_word2 + 1; j++ ){
            //相等则不需要操作
            if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            //插入操作 dp[i][j] = dp[i][j - 1]
            //删除操作 dp[i][j] = dp[i - 1][j]
            //替换操作 dp[i][j] = dp[i - 1][j - 1]
            else dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
        }
    }
    return dp[len_word1][len_word2];
}
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
动态规划|O(mn)|O(mn)
#### 3.1.3 难点分析
1. 求出 dp 递推表达式
2. dp 边界初始化
### 3.2 拓展
将 word1 转换成 word2 所使用的最少操作数其实可以作为一个单词相关性的衡量，然后再去做其他分析，比如现在比较火的文本分析等等。
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
