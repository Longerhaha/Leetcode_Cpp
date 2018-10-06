# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 022_(括号生成)Generate Parentheses
## 问题描述、输入输出与样例

### 问题描述

给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

### 函数输入与输出

* 输入：
	* int n：生成括号的对数
* 输出：
	* vector<string>：所有可能的并且有效的括号组合列表
	
### 问题样例

#### 示例1

输入: n = 3

输出:

	[
	  "((()))",
	  "(()())",
	  "(())()",
	  "()(())",
	  "()()()"
	]
	
	
## 思路描述与代码	
### 思路描述（深度遍历法）
函数体： DFS(vector<string> &ans, string path, int left, int right)

left 记录左括号的数目，right 记录右括号的数目，path 记录遍历的路径， ans 记录所有可能的并且有效的括号组合列表。

如果 left 和 right 都为0，则记录路径；

若 left > 0 ：DFS(ans, path + '(', left - 1, right + 1);

若 right > 0 ：DFS(ans, path + ')', left, right - 1);

### 代码
```cpp
void generateParenthesis_dfs(vector<string> &ans, string path, int left, int right){
	if(left == 0 && right == 0){
		ans.push_back(path);
		return ;
	}
	if(left > 0){
		generateParenthesis_dfs(ans, path + '(', left - 1, right + 1);
	}
	if(right > 0){
		generateParenthesis_dfs(ans, path + ')', left, right - 1);
	}
	
}
vector<string> generateParenthesis(int n) {
	vector<string> ans;
	string path;
	generateParenthesis_dfs(ans, path, n, 0);
	return ans;
}
```
## 思考与拓展
### 思考
回溯法在本题则显得有点不知所措，DFS思路则更为清楚。
### 拓展
暂无想法。


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
