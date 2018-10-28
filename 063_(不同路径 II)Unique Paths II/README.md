# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 063_(不同路径 II)Unique Paths II
## 1 问题描述、输入输出与样例
### 1.1 问题描述
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。<br>
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。<br>
现在考虑网格中有障碍物(障碍物和空位置分别用 1 和 0 来表示)。那么从左上角到右下角将会有多少条不同的路径？(图可以参见[63 不同路径](https://leetcode-cn.com/problems/unique-paths-ii/))<br>
__说明__：m 和 n 的值均不超过 100。
### 1.2 输入与输出
输入：
* vector<vector<int>>& obstacleGrid：含有障碍物的网格二维数据
输出：
* int: 从左上角到右下角的不同的路径数目
### 1.3 样例
#### 1.3.1 样例1
输入:<br>
[<br>
　[0,0,0],<br>
　[0,1,0],<br>
　[0,0,0]<br>
]<br>
输出: 2<br>
解释:<br>
3x3 网格的正中间有一个障碍物。<br>
从左上角到右下角一共有 2 条不同的路径：<br>
1. 向右 -> 向右 -> 向下 -> 向下<br>
2. 向下 -> 向下 -> 向右 -> 向右<br>

## 2 思路描述与代码	
### 2.1 思路描述（动态规划方法）
dp[i][j] 代表从左上角(1, 1)到网格(i + 1, j + 1)的路径总数；<br>
到点(i, j)的路只有经过(i - 1, j)和(i, j - 1)的两条路，但是假如这个点是障碍的话则没有路径到这个点，所以有:<br>
dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];。
### 2.2 代码
```cpp
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    //边界
    dp[0][0] = !obstacleGrid[0][0];
    for( int i = 1; i < m; i++ ) dp[i][0] = dp[i - 1][0] && !obstacleGrid[i][0];
    for( int j = 1; j < n; j++ ) dp[0][j] = dp[0][j - 1] && !obstacleGrid[0][j];
    //迭代
    for( int i = 1; i < m; i++ ){
        for(int j = 1; j < n; j++ ){
            //上方往下的路和左方往右的路
            dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
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
1. 找到DP递推表达式，这题递推表达式主要要考虑障碍;
2. 边界初始化。
### 3.2 拓展
暂无想法。
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
