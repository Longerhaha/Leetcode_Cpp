# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 064_(最小路径和)Minimum Path Sum
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。<br>
__说明__：每次只能向下或者向右移动一步。
### 1.2 输入与输出
输入：
* vector<vector<int>>& grid:网格二维数组 grid

输出：
* int:最小路径和
### 1.3 样例
#### 1.3.1 样例1
输入:<br>
[<br>
　[1,3,1],<br>
　[1,5,1],<br>
　[4,2,1]<br>
]<br>
输出: 7<br>
解释: 因为路径 1→3→1→1→1 的总和最小。
## 2 思路描述与代码	
### 2.1 思路描述（一维动态规划方法）
n 为列数<br>
dp[j]存储遍历当前 i 行节点 grid[i][j]的最小路径和, pre_row_dp[j]存储上一行即 i - 1 行节点 grid[i - 1][j]的最小路径和<br>
则:<br>
dp[i]　=　pre_row_dp[j] + grid[i][j], if(j == 0)<br>
　　　　　min(dp[j - 1], pre_row_dp[j]) + grid[i][j], else<br>
### 2.2 代码
```cpp
int minPathSum(vector<vector<int>>& grid) {
    //动态规划
    //dp[i][j] 代表从左上角(1, 1)到网格(i + 1, j + 1)的最小路径和
    int m = grid.size();
    int n =  grid[0].size();
    vector<int> dp(n, 0);
    //边界初始化
    dp[0] = grid[0][0];
    for( int j = 1; j < n; j++) dp[j] = dp[j - 1] + grid[0][j];
    //二维DP一维化的关键是存储上一行的DP
    vector<int> pre_row_dp(dp);
    for( int i = 1; i < m; i++ ){
        for( int j = 0; j < n; j++ ){
            if(j == 0) dp[j] = pre_row_dp[j] + grid[i][j];
            else dp[j] = min(dp[j - 1], pre_row_dp[j]) + grid[i][j];
        }
        pre_row_dp = dp;
    }
    return dp[n - 1];
    
    
}
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
##### 二维DP
递推式：<br>
dp[i][j]　=　　　dp[i - 1][j] + grid[i][j], if(j == 0)<br>
　　　　　　　min(dp[i - 1][j -1], dp[i - 1][j]) + grid[i][j], else<br>
##### DFS
DFS思路很简单，但是当输入数据的维度变大了之后，空间复杂度变得非常大，然后超内存。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
一维DP|O(n)|O(mn)
二维DP|O(mn)|O(mn)
#### 3.1.3 难点分析
1. 如何二维DP一维化；
2. 如何求递推公式。
### 3.2 拓展
如果让你求最大路径和呢？
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
