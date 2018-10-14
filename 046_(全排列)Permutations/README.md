# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 046_(全排列)Permutations
## 问题描述、输入输出与样例

### 问题描述

给定一个没有重复数字的序列，返回其所有可能的全排列。

### 函数输入与输出

* 输入：
	* vector<int>& nums：无重复数字的序列
* 输出：
	* vector<vector<int>>：全排列的结果列表，每个列表元素也是一个列表
	
### 问题样例

#### 示例1

输入: [1,2,3]

输出:

	[
	  [1,2,3],
	  [1,3,2],
	  [2,1,3],
	  [2,3,1],
	  [3,1,2],
	  [3,2,1]
	]
	
	
## 思路描述与代码	
### 思路描述（回溯法）
这是一道典型的回溯题目，其解空间是排列树。

此类方法的解题模板如下：
```cpp
for( int i = idx ; i < nums.size(); i++ ){
	//交换
	swap(nums[idx], nums[i]);
	permute_backtrack(ans, nums, idx + 1);
	//反交换，恢复原样
	swap(nums[i], nums[idx]);
}
```
### 代码
```cpp
void permute_backtrack(vector<vector<int>> &ans, vector<int>& nums, int idx){
	if(idx == nums.size()){
		ans.push_back(nums);
		return ;
	}
	
	for( int i = idx ; i < nums.size(); i++ ){
		swap(nums[idx], nums[i]);
		permute_backtrack(ans, nums, idx + 1);
		swap(nums[i], nums[idx]);
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> ans;
	permute_backtrack(ans, nums, 0);
	return ans;
}
```
## 思考与拓展
### 思考
本题就是基于排列树的回溯法，较为简单。
### 拓展
如果数据有重复且要求全排列里面的每个列表都不重复呢？
  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
