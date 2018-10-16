# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 040_(组合总和 II)Combination Sum II
## 问题描述、输入输出与样例

### 问题描述

给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

__说明__：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 

### 函数输入与输出

* 输入：
	* vector<int> &num：给定的可能包含重复数字的数组 candidates
	* int target：目标数 target
* 输出：
	* vector<vector<int>>：组合为 target 的所有不重复列表
	
### 问题样例

#### 示例1

输入: candidates = [10,1,2,7,6,1,5], target = 8,

输出:

	[
	  [1, 7],
	  [1, 2, 5],
	  [2, 6],
	  [1, 1, 6]
	]
	
#### 示例2

输入: candidates = [2,5,2,1,2], target = 5,

输出:

	[
	  [1,2,2],
	  [5]
	]


## 思路描述与代码	
### 思路描述（DFS）
与上一题的区别是 candidates 中的每个数字在每个组合中只能使用一次且输出不能重复。

照样还是 DFS，只不过递归的下一个要从下一个数开始，然后如果下一个数和当前数重复了则要跳过。

```cpp
path 记录路径， ans 记录所有可以组合为 target 的所有列表， start 记录起始的下标 

void DFS( ans, path, target, start ){
	if(target < 0) 此时无法继续寻找组合了，因为都是正整数，所以剪枝，break;
	else if(target == 0) 记录路径;
	
	for( i = start; i < candidates.size(); i++ ){
		//去重
		if(i > start && candidates[i] == candidates[i - 1]) continue;
		//记录路径
		path.push_back(candidates[i]);
		//递归下一个节点
		DFS(ans, path, target - candidates[i], i + 1);
		//恢复上一个节点的路径然后继续递归
		path.push_back(candidates[i]);
	}
} 
```

### 代码
```cpp
void combinationSum2_DFS(vector<vector<int> > &ans, vector<int> &num, vector<int> &path, int target, int start){
	if(target < 0) return ;
	else if(target == 0){
		ans.push_back(path);
		return;
	}
	for( int i = start; i < num.size(); i++ ){
		if(i > start && num[i] == num[i - 1]) continue;
		path.push_back(num[i]);
		combinationSum2_BackTrack(ans, num, path, target - num[i], i + 1);
		path.pop_back();
	}
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
	vector<vector<int> > ans;
	sort(num.begin(), num.end());
	vector<int> path;
	combinationSum2_DFS(ans, num, path, target, 0);
	return ans;
}
```
## 思考与拓展
### 思考
本题的DFS从下一个节点开始而不是从继续DFS当前节点，且需要去重。
### 拓展
如果给你的是链表数据呢？
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
