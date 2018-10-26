# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 062_(不同路径)Unique Paths
## 1 问题描述、输入输出与样例
### 1.1 问题描述
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。<br>
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。<br>
问总共有多少条不同的路径？(图可以参见[62 不同路径](https://leetcode-cn.com/problems/unique-paths/))<br>
__说明__：m 和 n 的值均不超过 100。
### 1.2 输入与输出
输入：
* int m: 网格的行数 
* int n: 网格的列数 

输出：
* int: 从“Start”到“Finish”的路径总数
### 1.3 样例
#### 1.3.1 样例1
输入: m = 3, n = 2<br>
输出: 3<br>
解释:<br>
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
#### 1.3.2 样例2
输入: m = 7, n = 3<br>
输出: 28
## 2 思路描述与代码	
### 2.1 思路描述（动态规划方法）
dp[i][j] 代表从左上角(1, 1)到网格(i + 1, j + 1)的路径总数；<br>
到点(i, j)的路只有经过(i - 1, j)和(i, j - 1)的两条路，所以有 dp[i][j] = dp[i - 1][j] + dp[i][j - 1]。
### 2.2 代码
```cpp
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    //边界
    for( int i = 0; i < m; i++ ) dp[i][0] = 1;
    for( int j = 0; j < n; j++ ) dp[0][j] = 1;
    //迭代
    for( int i = 1; i < m; i++ ){
        for(int j = 1; j < n; j++ ){
            //上方往下的路和左方往右的路
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
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
1. 找到DP递推表达式，这题递推表达式较为简单;
2. 边界初始化。
### 3.2 拓展
如果给你的网格是有障碍的呢？快尝试下[不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/)。
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
