# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 047_(全排列 II)Permutations II
## 问题描述、输入输出与样例

### 问题描述

给定一个可包含重复数字的序列，返回所有不重复的全排列

### 函数输入与输出

* 输入：
	* vector<int>& nums：可包含重复数字的序列
* 输出：
	* vector<vector<int>>：不重复的全排列的结果列表，每个列表元素也是一个列表
	
### 问题样例

#### 示例1

输入: [1,1,2]

输出:

	[
	  [1,1,2],
	  [1,2,1],
	  [2,1,1]
	]
	
	
## 思路描述与代码	
### 思路描述（回溯法）
这是一道典型的回溯题目，其解空间是排列树，关键在于如何去重。

这个需要从排列树的结构出发，对于当前排列树的分叉节点 i，假如这个排列的根节点是 start，如果 nums[i] 与 nums[start, start + 1, ... i-2, i-1]至少有一个节点则重复了，
因为这样的树在这个排列之前就已经存在了。 

此类方法的解题模板如下：
```cpp
for( int i = idx ; i < nums.size(); i++ ){
	//交换
	//如果 nums[i] 与 nums[start, start + 1, ... i-2, i-1]都不重复则可以继续下一个排列
	int j = i - 1;
	while(j >= start && nums[j] != nums[i]) j--;
	if(i == start || j == start - 1){
		swap(nums[i], nums[start]);
		permuteUnique_BacktTrack(ans, nums, start + 1);
		swap(nums[i], nums[start]);
	}

}
```
### 代码
```cpp
void permuteUnique_BacktTrack(vector<vector<int>> &ans, vector<int>& nums, int start){
	if(start == nums.size()) ans.push_back(nums);
	for( int i = start; i < nums.size(); i++ ){
		//去重
		//如果 nums[i] 与 nums[start, start + 1, ... i-2, i-1]都不重复则可以继续下一个排列
		int j = i - 1;
		while(j >= start && nums[j] != nums[i]) j--;
		if(i == start || j == start - 1){
			swap(nums[i], nums[start]);
			permuteUnique_BacktTrack(ans, nums, start + 1);
			swap(nums[i], nums[start]);
		}
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	vector<vector<int>> ans;
	vector<int> path;
	//sort(nums.begin(), nums.end());
	permuteUnique_BacktTrack(ans, nums, 0);
	return ans;
}
```
## 思考与拓展
### 思考
本题主要的关键在于去重，从排列树的结构出发则很容易知道如何去重。
### 拓展
暂无想法。
  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
