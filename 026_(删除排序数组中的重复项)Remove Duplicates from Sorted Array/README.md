# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 026_(删除排序数组中的重复项)Remove Duplicates from Sorted Array
## 问题描述、输入输出与样例

### 问题描述

给定一个排序数组，你需要在__原地__删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在__原地__修改输入数组并在使用 O(1) 额外空间的条件下完成。


说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

### 函数输入与输出

* 输入：
	* vector<int>& nums：输入的数组
* 输出：
	* int：删除重复项后的数据的长度
	
### 问题样例

#### 示例1

输入: nums = [1,1,2]

输出: 2

解释：函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 你不需要考虑数组中超出新长度后面的元素。
	
#### 示例2

输入: nums = [0,0,1,1,1,2,2,3,3,4]

输出: 5

解释：函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4, 你不需要考虑数组中超出新长度后面的元素。
	
## 思路描述与代码	
### 思路描述（计数法）
notDupNum 记录当前不重复节点的数目

遍历所有节点，如果不重复则把当前数据放在 nums[notDupNum]，同时 notDupNum 加1

### 代码
```cpp
int removeDuplicates(vector<int>& nums) {
	int len = nums.size();
	int notDupNum = len > 0 ? 1 : 0;
	for( int i = 1; i < len; i++ ){
		if(nums[i] != nums[i - 1]) nums[notDupNum++] = nums[i];
	}
	return notDupNum;
}
```
## 思考与拓展
### 思考
本题较为简单。
### 拓展
如果给你的数据是无序的而且要求的时间复杂度是O（n）呢？


# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
