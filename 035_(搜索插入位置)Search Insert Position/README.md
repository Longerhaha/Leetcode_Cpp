# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 035_(搜索插入位置)Search Insert Position
## 问题描述、输入输出与样例

### 问题描述

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

### 函数输入与输出

* 输入：
	* vector<int>& nums：给定的排序数组 nums 
	* int target：目标值 target
* 输出：
	* int：插入的位置
	
### 问题样例

#### 示例1

输入: [1,3,5,6], 5

输出: 2

#### 示例2

输入: [1,3,5,6], 2

输出: 1

#### 示例3

输入: [1,3,5,6], 7

输出: 4

#### 示例4

输入: [1,3,5,6], 0

输出: 0
	
	
## 思路描述与代码	
### 思路描述（二分法）
start 记录当前查找的范围的起始位置， end记录当前查找范围的结束位置
```cpp
while( start < end ){
	mid = (start + end) / 2;
	if(nums[mid] == target) return mid; 
	else if(nums[mid] < target) start = mid + 1;
	else end = mid;
}
跳出来后主要有两种情况
1. 当 target 比 nums[len - 1] 还大时，跳出来时 start = end =  len - 1 且 nums[start] < target
2. 当 target 比 nums[len - 1] 小时，跳出来时 start = end 且 nums[start] >= target
return nums[start] >= target ? start : len;
```

### 代码
```cpp
int searchInsert(vector<int>& nums, int target) {
	int len = nums.size();
	int start = 0, end = len - 1;
	//二分查找
	while( start < end ){
		int mid = (start + end) / 2;
		if(nums[mid] == target) return mid; 
		else if(nums[mid] < target) start = mid + 1;
		else end = mid;
	}
	//当 target 比 nums[len - 1] 还大时，跳出来时 start = end =  len - 1 且 nums[start] < target
	//当 target 比 nums[len - 1] 小时，跳出来时 start = end 且 nums[start] >= target
	return nums[start] >= target ? start : len;
}
```
## 思考与拓展
### 思考
本题主要的麻烦在于当 target 比 nums[len - 1] 还大时，跳出来时 start = end =  len - 1，恰好此时 nums[start] < target，以此区分与其他情况的差别。
### 拓展
如果数据中有重复元素呢？


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
