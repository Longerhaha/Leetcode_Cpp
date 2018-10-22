# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 053_(最大子序和)Maximum Subarray
## 问题描述、输入输出与样例

### 问题描述

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

__进阶__:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

### 函数输入与输出

* 输入：
	* vector<int>& nums：给定的整数数组 nums
* 输出：
	* int：最大子序和
	
### 问题样例

#### 示例1

输入: [-2,1,-3,4,-1,2,1,-5,4],

输出: 6

解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
	
	
## 思路描述与代码	
### 思路描述（在线处理法、分治法）

#### 在线处理法
其思想是如果当前累加的和 this_sum < 0，那么其肯定不会使得后续的子序更大，所以重新累加。
```cpp
len_nums 为输入数组的长度
max_sum 为记录的最大和
this_sum 记录当前累加的结果
for( i = 0; i < len_nums; i++ ){
	this_sum += nums[i];
	max_sum = max(max_sum, this_sum);
	if(this_sum < 0) this_sum = 0;
}
```
#### 分治法
分治主要有两个步骤，分和治。

把输入的 nums 数组一分为2，递归求左半部分的最大值 left_max，递归求右半部分的最大值 right_max，一遍扫描求跨越中间节点的最大子序和 across_mid_max，三者的最大值即为最大子序和。

### 代码
#### 在线处理
```cpp
int maxSubArray_online_processing(const vector<int>& nums){
	int len_nums = nums.size();
	int max_sum = MIN;
	int this_sum = 0;
	for( int i = 0; i < len_nums; i++ ){
		this_sum += nums[i];
		max_sum = max(max_sum, this_sum);
		if(this_sum < 0) this_sum = 0;
	}
	return max_sum;
}
```
#### 分治
```cpp
int maxSubArray_divideAndConquer(const vector<int>& nums, const int start, const int end){
	if(start == end) return nums[start];
	int mid = (start + end) / 2;
	//获取左、右部分最大值
	int left_max = maxSubArray_divideAndConquer(nums, start, mid);
	int right_max = maxSubArray_divideAndConquer(nums, mid + 1, end);
	//获取中间最大值
	int left_across_mid_max = MIN;
	int left_across_mid_sum = 0;
	for( int i = mid; i >= start; i-- ){
		left_across_mid_sum += nums[i];
		left_across_mid_max = max(left_across_mid_max, left_across_mid_sum);
	}
	int right_across_mid_max = MIN;
	int right_across_mid_sum = 0;
	for( int i = mid + 1; i <= end; i++ ){
		right_across_mid_sum += nums[i];
		right_across_mid_max = max(right_across_mid_max, right_across_mid_sum);
	}
	int across_mid_max = left_across_mid_max + right_across_mid_max;
	return max(left_max, max(right_max, across_mid_max));
}
```
## 思考与拓展
### 思考
在线处理的时间复杂度为O(n)，分治的空间复杂度为O(nlogn)，二者的思想都值得回味。 
### 拓展
本题可以有很多变形，可以尝试[最小子序列和](https://blog.csdn.net/u011493189/article/details/52409375)。


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
