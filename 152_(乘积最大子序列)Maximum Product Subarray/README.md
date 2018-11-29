# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 152_(乘积最大子序列)Maximum Product Subarray
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
### 1.2 输入与输出
输入：<br>
* vector<int>& nums:给定的整数数组<br>
输出：<br>
* int:乘积最大的连续子序列<br>
### 1.3 样例
#### 1.3.1 样例1
输入: [2,3,-2,4]<br>
输出: 6<br>
解释: 子数组 [2,3] 有最大乘积 6。<br>
#### 1.3.2 样例2
输入: [-2,0,-1]<br>
输出: 0<br>
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。<br>
## 2 思路描述与代码	
### 2.1 思路描述（动态规划）
对于给定的数组，对于nums[i]找寻找nums[0,1,...i-1]其最大的子序列只有三种情况<br>
1. nums[i] 是正数，则最大子序列为 包括nums[i - 1]的子序列的最大积乘以nums[i]
2. nums[i] 是负数，则最大子序列为 包括nums[i - 1]的子序列的最小积乘以nums[i]
3. nums[i] 最大

显然我们需要维护两个数组，其中 dp_pos_max[i] 是包括 nums[i - 1] 的子序列的最大积， dp_neg_min[i] 是包括 nums[i - 1] 的 子序列的最小积<br>
遍历一遍后直接返回 dp_pos_max 数组的最大值即可。
```cpp
maxProd = dp_pos_max[0] = dp_neg_min[0] = nums[0];
for( int i = 1; i < n; i++ ){
    dp_pos_max[i] = max(dp_pos_max[i - 1] * nums[i], max(dp_neg_min[i - 1] * nums[i], nums[i]));
    dp_neg_min[i] = min(dp_neg_min[i - 1] * nums[i], min(dp_pos_max[i - 1] * nums[i], nums[i]));
}
return max(dp_pos_max);
```
### 2.2 代码
```cpp
int maxProduct(vector<int>& nums) {
    int len = nums.size();
    vector<int> dp_pos_max(len, -2147483648);
    vector<int> dp_neg_min(len, 2147483647);
    int maxProd;
    maxProd = dp_pos_max[0] = dp_neg_min[0] = nums[0];
    for( int i = 1; i < len; i++ ){
        dp_pos_max[i] = max(dp_pos_max[i - 1] * nums[i], max(dp_neg_min[i - 1] * nums[i], nums[i]));
        dp_neg_min[i] = min(dp_neg_min[i - 1] * nums[i], min(dp_pos_max[i - 1] * nums[i], nums[i]));
        maxProd = max(maxProd, dp_pos_max[i]);
    }
    return maxProd;
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
1. 分析乘积最大子序列的情况
2. 求出动态规划的式子
### 3.2 拓展
无。
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
