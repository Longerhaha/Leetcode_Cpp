# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 033_(搜索旋转排序数组)Search in Rotated Sorted Array
## 问题描述、输入输出与样例

### 问题描述

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

### 函数输入与输出

* 输入：
	* vector<int>& nums：旋转排序数组 
	* int target：目标元素 target
* 输出：
	* int：target 在排序数组中的下标
	
### 问题样例

#### 示例1

输入: nums = [4,5,6,7,0,1,2], target = 0

输出: 4

#### 示例2

输入: nums = [4,5,6,7,0,1,2], target = 3

输出: -1
	
## 思路描述与代码	
### 思路描述（二分法）
题目要求算法时间复杂度必须是 O(log n) 级别，所以肯定是使用二分法了。

其次要了解排序数组的性质：旋转后，其左半部分或者右半部分还是有序的。

有了上述性质，接下来就和二分思想差不多了。

start 为当前搜索的第一个元素的位置， end 为搜索的最后一个元素的位置;
```cpp
while( start < end ){
	mid  = (start + end) / 2;
	if(nums[mid] == target) 返回 mid;
	else if(nums[start] <= nums[mid]){
		//说明左半部分有序、右半部分无序
		if(target 在左半部分的范围内) end = mid - 1;
		else start = mid + 1;
	}
	else{
		//说明右半部分有序、左半部分无序
		if(target 在右半部分的范围内) start = mid + 1;
		else end = mid - 1;
	}
}
返回 nums[start] == target ? start : -1;
```
### 代码
```cpp
int search(vector<int>& nums, int target) {
	int len = nums.size();
	if(len == 0) return -1;
	int start = 0, end = len - 1;
	while(start < end){
		int mid = (start + end) / 2;
		if(nums[mid] == target) return mid;
		//左边有序、右边乱序
		else if(nums[start] <= nums[mid]){
			if(nums[start] <= target && target < nums[mid]) end = mid - 1;
			else start = mid + 1;
		}
		//右边有序、左边乱序
		else{
			if(nums[mid] < target && target <= nums[end]) start = mid + 1;
			else end = mid - 1;
		}
	}
	return nums[start] == target ? start : -1;
}
```
## 思考与拓展
### 思考
理解排序数组的特性是用二分解本题的关键。
### 拓展
如果给定的数组有重复呢？


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
