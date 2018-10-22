# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 052_(N皇后 II)N-Queens II
## 问题描述、输入输出与样例

### 问题描述

n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给定一个整数 n，返回 n 皇后不同的解决方案的数量。

### 函数输入与输出

* 输入：
	* int n： n×n 的棋盘
* 输出：
	* int：n 皇后不同的解决方案的数量
	
### 问题样例

#### 示例1

输入: 4

输出: 2

解释: 4 皇后问题存在如下两个不同的解法。

	[
	 [".Q..",  // 解法 1
	  "...Q",
	  "Q...",
	  "..Q."],

	 ["..Q.",  // 解法 2
	  "Q...",
	  "...Q",
	  ".Q.."]
	]

## 思路描述与代码	
### 思路描述（回溯法）
基于子集树的回溯法，在52题的基础上改编即可。

### 代码
```cpp
bool bound(const vector<int> &pos, const int check_idx){
	for( int i = 0; i < check_idx; i++ ){
		if(pos[i] == pos[check_idx] || abs(i - check_idx) == abs(pos[i] - pos[check_idx])) return false; 
	}
	return true;
}

void solveNQueens_backtrack(int &solver_num, vector<int> &pos, const int size, int start){
	if(start == size){
		solver_num++;
		return ;
	}
	for( int i = 0; i < size; i++ ){
		pos[start] = i;
		if(bound(pos, start)) solveNQueens_backtrack(solver_num, pos, size, start + 1);
	}
}

int totalNQueens(int n) {
	int solver_num = 0;
	vector<int> pos(n, 0);
	solveNQueens_backtrack(solver_num, pos, n, 0);
	return solver_num;
}
```
## 思考与拓展
### 思考
本题是经典的基于子集树空间的回溯法。
### 拓展
暂无想法。
  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
