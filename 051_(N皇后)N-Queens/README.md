# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 051_(N皇后)N-Queens
## 问题描述、样例与输入输出

### 问题描述

皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击（不在同一行、列、对角线）。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

### 问题样例

	示例1:
	输入: 
	4
	  
	输出: 
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
	解释：
	4 皇后问题存在两个不同的解法。
	
### 函数输入与输出

* 输入：
	* int n： n 个皇后
* 输出：
	* vector<vector<string>>：解法。

## 思路	
### 回溯

    //界限函数
    bool Bound(vector<int> &pos, int idx){
        for( int i = 0; i < idx ; i++ ){
            //如果不在同一列或者对角线
            if(pos[idx] == pos[i] || abs(pos[idx] - pos[i]) == abs(idx - i)) return false;
        }
        return true;
    }
    //解空间树是子集树的的回溯
    void solveNQueens_backtrack(vector<vector<string>> &ans, vector<int> &pos, int n, int idx){
        if(idx == n){
            //根据pos生成方案
            vector<string> scheme;
            for( int i = 0; i < n; i++ ){
                string row_str;
                row_str.insert(0, pos[i], '.');
                row_str.insert(pos[i], 1, 'Q');
                row_str.insert(pos[i] + 1, n - pos[i] - 1, '.');
                scheme.push_back(row_str);
            }
            ans.push_back(scheme);
            return ;
        }
        //子集树 
        for( int i = 0; i < n; i++ ){
            pos[idx] = i;
            if(Bound(pos, idx)) solveNQueens_backtrack(ans, pos, n, idx + 1);
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> pos(n);
        solveNQueens_backtrack(ans, pos, n, 0);
        return ans;
    }

		

 
## 拓展与思考：
### 拓展
暂无想法。
### 思考
本题，利用回溯（解空间是子集树）即可。	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
