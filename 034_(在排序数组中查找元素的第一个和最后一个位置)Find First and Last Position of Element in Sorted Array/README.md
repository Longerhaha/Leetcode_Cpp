# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 034_(在排序数组中查找元素的第一个和最后一个位置)Find First and Last Position of Element in Sorted Array
## 问题描述、输入输出与样例

### 问题描述

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

### 函数输入与输出

* 输入：
	* vector<int>& nums：给定按照升序排列的整数数组 nums
	* int target：目标值 target
* 输出：
	* vector<int>：目标值在数组中的开始位置和结束位置
	
### 问题样例

#### 示例1

输入: nums = [5,7,7,8,8,10], target = 8

输出: [3,4]

#### 示例2

输入: nums = [5,7,7,8,8,10], target = 6

输出: [-1,-1]
	
	
## 思路描述与代码	
### 思路描述（二分法）
start 记录当前查找的范围的起始位置， end记录当前查找范围的结束位置， ans 为记录 target 的第一个和最后一个位置的列表
```cpp
while( start < end ){
	mid = (start + end) / 2;
	if(nums[mid] == target){
		left = mid;
		end = mid;
		左右扩张与target相等的范围、记录位置至 ans 并返回 ans
	}
	else if(nums[mid] < target) start = mid + 1;
	else end = mid - 1;
}
如果没有返回，此时start == end
if(nums[mid] == target) 记录两个 mid 至 ans 列表中
else 记录两个 -1 至 ans 列表中
返回ans
```

### 代码
```cpp
vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> ans;
	int len = nums.size();
	//输入为空时，返回-1、-1
	if(len == 0){
		ans.push_back(-1);
		ans.push_back(-1);
		return ans;
	}
	//二分查找
	int start = 0, end = len - 1;
	while( start < end ){
		int mid = (start + end) / 2;
		if(nums[mid] == target){
			//左右扩张与target相等的范围
			int left = mid;
			int right = mid;
			while( left - 1 >= start && target == nums[left - 1] ) left--;
			while( right + 1 <= end && target == nums[right + 1] ) right++;
			ans.push_back(left);
			ans.push_back(right);
			return ans;
		}
		else if(nums[mid] < target) start = mid + 1;
		else end = mid - 1;
	}
	if(nums[start] == target){
		ans.push_back(start);
		ans.push_back(end);
	}
	else{
		ans.push_back(-1);
		ans.push_back(-1);
	}
	return ans;
}
```
## 思考与拓展
### 思考
题目要求时间复杂度必须是 O(log n) 级别，所以肯定是用二分。本文里面的二分法的平均时间复杂度为 O(log n)， 最坏复杂度为 O（n）。
### 拓展
如果给你的是链表数据呢？
  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
