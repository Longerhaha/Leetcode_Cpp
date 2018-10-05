# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 016_(最接近的三数之和)3Sum Closet
## 问题描述、输入输出与样例

### 问题描述

给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。

### 函数输入与输出

* 输入：
	* vector<int>& nums：输入的包括 n 个整数的数组 nums
	* int target：目标值
* 输出：
	* int：最接近目标值的三个数的和
	
### 问题样例

#### 示例1

输入: nums = [-1，2，1，-4], target = 1.

输出: 2

解释：与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
	
	
## 思路描述与代码	
### 思路描述（双指针法）
1. 排序
2. closet 记录当前与 target 最近接的三个数的和，遍历 nums 数组中所有的数 x ：
	* （1）算 x + *ptr1 + *ptr2的值，若其与 target 的差距比 closet 小，则更新 closet
	* （2）如果closet == target 则返回 closet；否则若是 closet < target，则 ptr1++；否则ptr2++

### 代码
```cpp
int threeSumClosest(vector<int>& nums, int target) {
	int len = nums.size();
	sort(nums.begin(), nums.end());
	int closet = nums[0] + nums[1] + nums[2];
	for( int i = 0; i < len; i++ ){
		int start = i + 1;
		int end = len - 1;
		while( start < end ){
			int three_sum = nums[i] + nums[start] + nums[end];
			closet = abs(target - closet) < abs(target - three_sum) ? closet : three_sum;
			if(target - three_sum == 0) return closet;
			else if(target - three_sum > 0) start++;
			else end--;
		}
	}
	return closet;
}
```
## 思考与拓展
### 思考
本题从三数之和变形即可，甚至可以说这题比三数之和简单多了，因为不需要考虑重复的问题。
### 拓展
若是让你求最接近的二数之和呢？可以实现O（n）的时间复杂度吗？


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
