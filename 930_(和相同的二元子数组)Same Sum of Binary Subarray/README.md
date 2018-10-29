# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 930_(和相同的二元子数组)Same Sum of Binary Subarray
## 1 问题描述、输入输出与样例
### 1.1 问题描述
在由若干 0 和 1  组成的数组 A 中，有多少个和为 S 的非空子数组。<br>
__提示__：
1. A.length <= 30000
2. 0 <= S <= A.length
3. A[i] 为 0 或 1
### 1.2 输入与输出
输入：
* vector<int>& A:由若干 0 和 1 组成的数组 A
* int S:和为 S 

输出：
* int:多少个和为 S 的非空子数组
### 1.3 样例
#### 1.3.1 样例1
输入：A = [1,0,1,0,1], S = 2<br>
输出：4<br>
解释：<br>
如下面黑体所示，有 4 个满足题目要求的子数组：<br>
[1,0,1,0,1]<br>
[1,0,1,0,1]<br>
[1,0,1,0,1]<br>
[1,0,1,0,1]<br>
## 2 思路描述与代码	
### 2.1 思路描述（动态规划方法）
len 为数组 A 的个数；<br>
dp[i] 代表 以A[0]为起始点的子数组且和为 i 的个数；<br>
则和为 S 的个数为 = sum(num[A[0]], num[A[1]], ..., num[A[len - 1]])，其中num[A[i]]为以A[i]为子数组的最后一个位置且和为 S 的个数)，且有 num[A[i]] = sum(A[0], A[1], ..., A[i]) - S >= 0 ? dp[sum(A[0], A[1], ..., A[i]) - S] : 0；<br>
然后根据公式遍历即可。
### 2.2 代码
```cpp
int numSubarraysWithSum(vector<int>& A, int S) {
    int len = A.size();
    //dp[i] 代表 以A[0]为起始点，和为 i 的个数
    //则和为 S 的个数为 = sum(num[A[0]], num[A[1]], ..., num[A[len - 1]])，其中num[A[i]]为以A[i]为子数组的最后一个位置且和为 S 的个数)，如不存在这样的数组则num[A[i]]为0
    //num[A[i]] = sum(A[0], A[1], ..., A[i]) - S >= 0 ? dp[sum(A[0], A[1], ..., A[i]) - S] : 0;
    vector<int> dp(len + 1, 0);
    dp[0] = 0;
    int sum = 0;
    int ans = 0;
    for( auto a : A ){
        dp[sum]++;
        sum += a;
        if(sum >= S) ans += dp[sum - S];
    }
    return ans;
}
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
动态规划|O(n)|O(n)
#### 3.1.3 难点分析
1. 求和为 S 的子数组的个数划分为sum(num[A[0]], num[A[1]], ..., num[A[len - 1]])；
2. 建立 num 数组与 dp 数组的联系，即二者的换算公式。
### 3.2 拓展
如果给你的是十元数组呢？利用DP空间来存储和还划算吗？如果不划算需要使用什么数据结构来存？
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
