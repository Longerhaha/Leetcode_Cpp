# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 039_(组合总和)Combination Sum
## 问题描述、输入输出与样例

### 问题描述

给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

* 所有数字（包括 target）都是正整数。
* 解集不能包含重复的组合。 

### 函数输入与输出

* 输入：
	* vector<int>& candidates：输入无重复元素的数组 candidates 
* 输出：
	* vector<vector<int>>：组合为 target 的所有列表
	
### 问题样例

#### 示例1

输入: candidates = [2,3,6,7], target = 7,

输出:

	[
	  [7],
	  [2,2,3]
	]
	
#### 示例2

输入: candidates = [2,3,5], target = 8,

输出:

	[
	  [2,2,2,2],
	  [2,3,3],
	  [3,5]
	]
	
	
## 思路描述与代码	
### 思路描述（回溯法）
本题列举所有的可能性，很明显是用回溯方法做。

```cpp
path 记录路径， ans 记录所有可以组合为 target 的所有列表， start 记录起始的下标 

void backtrack( ans, path, start, target ){
	if(target < 0) 此时无法继续寻找组合了，因为都是正整数，所以剪枝，break;
	else if(target == 0) 记录路径;
	
	for( i = start; i < candidates.size(); i++ ){
		记录路径, path.push_back(candidates[i]);
		backtrack(ans, path, start, taeget - candidates[i]);
		恢复上一个节点的树状然后继续下一个分叉, path.push_back(candidates[i]);
	}
} 
```

### 代码
```cpp
void combinationSum_BackTrack(vector<vector<int>>& ans, vector<int>& path, vector<int>& candidates, int target, int start){
	if(target == 0){
		ans.push_back(path);
		return ;
	}
	else if(target < 0) return ;

	for( int i = start; i < candidates.size(); i++ ){
		path.push_back(candidates[i]);
		combinationSum_BackTrack(ans, path, candidates, target - candidates[i], i);
		path.pop_back();
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	vector<int> path;
	combinationSum_BackTrack(ans, path, candidates, target, 0);
	return ans;
}
```
## 思考与拓展
### 思考
本题可以利用都是正整数进行剪枝，其他不难。
### 拓展
如果输入的有重复数字呢？


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
