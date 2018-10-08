# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 027_(移除元素)Remove Element
## 问题描述、输入输出与样例

### 问题描述

给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);

// 在函数里修改输入数组对于调用者是可见的。

// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
```cpp
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```
### 函数输入与输出

* 输入：
	* vector<int>& nums：输入的数组
* 输出：
	* int：删除重复项后的数据的长度
	
### 问题样例

#### 示例1

输入: nums = [3,2,2,3], val = 3

输出: 2

解释：函函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。
	
#### 示例2

输入: nums = [0,1,2,2,3,0,4,2], val = 2,

输出: 5

解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

注意这五个元素可为任意顺序。

你不需要考虑数组中超出新长度后面的元素。
	
## 思路描述与代码	
### 思路描述（计数法）
notEqualValNum 记录当前与 val 不相等的数目

遍历所有节点，如果与 val 不相等则把当前数据放在 nums[notEqualValNum]，同时 notEqualValNum 加1

### 代码
```cpp
int removeElement(vector<int>& nums, int val) {
	int notEqualValNum = 0;
	for( int i = 0; i < nums.size(); i++ ){
		if(nums[i] != val) nums[notEqualValNum++] = nums[i];
	}
	return notEqualValNum;
}
```
## 思考与拓展
### 思考
本题较为简单。
### 拓展
暂无想法。


# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
