# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 931_(下降路径最小和)Minimum Sum of Descending Path
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个方形整数数组 A，我们想要得到通过 A 的__下降路径__的最小和。<br>
下降路径可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列。
### 1.2 输入与输出
输入：
* vector<vector<int>>& A:方形整数数组 A

输出：
* int:最小的下降路径和
### 1.3 样例
#### 1.3.1 样例1
输入：[[1,2,3],[4,5,6],[7,8,9]]<br>
输出：12<br>
解释：<br>
可能的下降路径有：
* [1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
* [2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
* [3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]

和最小的下降路径是 [1,4,7]，所以答案是 12。
## 2 思路描述与代码	
### 2.1 思路描述（一维动态规划方法）
n 为列数<br>
dp[j]存储遍历当前 i 行节点 A[i][j]的下降路径的最小和, pre_row_dp[j]存储上一行即 i - 1 行节点 A[i - 1][j]的下降路径的最小和<br>
则:<br>
　　　　　min(pre_row_dp[j - 1], pre_row_dp[j]) + A[i][j], if(j == n - 1)<br>
dp[i]　=　min(pre_row_dp[j], pre_row_dp[j + 1]) + A[i][j], if(j == 0)<br>
　　　　　min(pre_row_dp[j - 1], min(pre_row_dp[j], pre_row_dp[j + 1])) + A[i][j], else<br>
### 2.2 代码
```cpp
int minFallingPathSum(vector<vector<int>>& A) {
    int m = A.size();
    int n = A[0].size();
    if(m == 0 || n == 0) return 0;
    else if(m == 1) return accumulate(A[0].begin(), A[0].end(), 0);
    else if(n == 1){
        int sum = 0;
        for( int i = 0; i < m; i++ ) sum += A[i][0];
        return sum;
    }
    
    //二维 dp 一维化，节省内存
    vector<int> dp(n, 0);
    vector<int> pre_row_dp(dp);
    for( int i = 0; i < m; i++ ){
        for( int j = 0; j < n; j++ ){
            if(j == 0) dp[j] = min(pre_row_dp[j], pre_row_dp[j + 1]) + A[i][j];
            else if(j == n - 1) dp[j] = min(pre_row_dp[j - 1], pre_row_dp[j]) + A[i][j];
            else dp[j] = min(pre_row_dp[j - 1], min(pre_row_dp[j], pre_row_dp[j + 1])) + A[i][j];
        }
        pre_row_dp = dp;
    }
    return *min_element(dp.begin(), dp.end());
}
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
##### 二维DP
递推式：<br>
　　　　　　　min(dp[i - 1][j -1], dp[i - 1][j]) + A[i][j], if(j == n - 1)<br>
dp[i][j]　=　　　min(dp[i - 1][j], dp[i - 1][j + 1]) + A[i][j], if(j == 0)<br>
　　　　　　　min(dp[i - 1][j -1], min(dp[i - 1][j], dp[i - 1][j + 1])) + A[i][j], else<br>
##### DFS
DFS思路很简单，但是当输入数据的维度变大了之后，空间复杂度变得非常大，然后超内存。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
一维DP|O(n)|O(n^2)
二维DP|O(n^2)|O(n^2)
#### 3.1.3 难点分析
1. 如何二维DP一维化。
### 3.2 拓展
本题就是[最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)的翻版。
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
