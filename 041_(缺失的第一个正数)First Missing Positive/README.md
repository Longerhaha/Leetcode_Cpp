# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 041_(缺失的第一个正数)First Missing Positive
## 问题描述、输入输出与样例

### 问题描述

给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

__说明__:

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间
### 函数输入与输出

* 输入：
	* vector<int>& nums：未排序的整数数组
* 输出：
	* int：没有出现的最小的正整数
	
### 问题样例

#### 示例1

输入: [1,2,0]

输出: 3

#### 示例2

输入: [3,4,-1,1]

输出: 2
	
#### 示例3

输入: [7,8,9,11,12]

输出: 1
	
## 思路描述与代码	
### 思路描述（对号入座法）
对于这类题目，都是采用对号入座法才能实现 O(n) 的时间复杂度和常数级别空间复杂度。
```cpp
for( int i = 0; i < len; i++ ){
	//在合理的范围内且 nums[i] 不等于 i + 1 且 nums[i] != nums[nums[i] - 1] 则交换
	//值得注意的是如果没有 nums[i] != nums[nums[i] - 1] 这个限制，则会陷入无止境的交换
	while(nums[i] >= 1 && nums[i] <= len && nums[i] != nums[nums[i] - 1] && nums[i] != i + 1) swap(nums[i], nums[nums[i] - 1]);
}

```
### 代码
```cpp
//对号入座 nums[i] 放 i + 1
int firstMissingPositive(vector<int>& nums) {
	int len = nums.size();
	for( int i = 0; i < len; i++ ){
		while(nums[i] >= 1 && nums[i] <= len && nums[i] != nums[nums[i] - 1] && nums[i] != i + 1) swap(nums[i], nums[nums[i] - 1]);
	}
	
	for( int i = 0; i < len; i++ ){
		if(nums[i] != i + 1) return i + 1;
	}
	return len + 1;
}
```
## 思考与拓展
### 思考
本题使用对号入座法才能实现 O(n) 的时间复杂度和常数级别空间复杂度，对号入座法也是这类题目常见的解法。
### 拓展
如果给你的是链表数据呢？


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
