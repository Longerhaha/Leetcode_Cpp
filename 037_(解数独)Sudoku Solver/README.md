# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 037_(解数独)Sudoku Solver
## 问题描述、输入输出与样例

### 问题描述

编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

1. 数字 1-9 在每一行只能出现一次。
2. 数字 1-9 在每一列只能出现一次。
3. 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

空白格用 '.' 表示。

__注意__:

1. 给定的数独序列只包含数字 1-9 和字符 '.' 。
2. 你可以假设给定的数独只有唯一解。
3. 给定数独永远是 9x9 形式的。

### 函数输入与输出

* 输入：
	* vector<vector<char>>& board：数独的二维矢量
* 输出：
	* void：原地修改
	
### 问题样例

#### 示例1

输入: 

	[["5","3",".",".","7",".",".",".","."],
	 ["6",".",".","1","9","5",".",".","."],
	 [".","9","8",".",".",".",".","6","."],
	 ["8",".",".",".","6",".",".",".","3"],
	 ["4",".",".","8",".","3",".",".","1"],
	 ["7",".",".",".","2",".",".",".","6"],
	 [".","6",".",".",".",".","2","8","."],
	 [".",".",".","4","1","9",".",".","5"],
	 [".",".",".",".","8",".",".","7","9"]]

输出:

	[["5","3","4","6","7","8","9","1","2"],
	 ["6","7","2","1","9","5","3","4","8"],
	 ["1","9","8","3","4","2","5","6","7"],
	 ["8","5","9","7","6","1","4","2","3"],
	 ["4","2","6","8","5","3","7","9","1"],
	 ["7","1","3","9","2","4","8","5","6"],
	 ["9","6","1","5","3","7","2","8","4"],
	 ["2","8","7","4","1","9","6","3","5"],
	 ["3","4","5","2","8","6","1","7","9"]]
	
	
## 思路描述与代码	
### 思路描述（DFS）
validMat[0][idx1][idx2]代表第 idx1 行的 字符 idx2 + 1已经存在
validMat[1][idx1][idx2]代表第 idx1 列的 字符 idx2 + 1已经存在
validMat[2][idx1][idx2]代表第 idx1 块的 字符 idx2 + 1已经存在

1. 首先遍历一遍输入数独的二维矢量，然后记录数字字符相应的 validMat；

2. 从下标[0,0]开始遍历数独二维矢量：

```cpp
your code
```
SudokuSize = 9;
SudokuSizeBlock = 3;

bool solveSudoku_dfs(vector<vector<char>>& board, int row_idx, int col_idx){
	//遍历结束且DFS路径可行返回true
	if(row_idx == SudokuSize && col_idx == SudokuSize - 1) return true;
	//当前列DFS完了，DFS下一列
	if(row_idx == SudokuSize) return solveSudoku_dfs(board, 0, col_idx + 1);
	//如果是数字字符，直接DFS
	if(board[row_idx][col_idx] != '.'){
		return solveSudoku_dfs(board, row_idx + 1, col_idx);
	}
	else{
		for( int k = 1; k <= SudokuSize; k++ ){
			//如果字符 k 合理
			if(!validMat[0][row_idx][k - 1] && !validMat[1][col_idx][k - 1] && !validMat[2][row_idx/SudokuSizeBlock * SudokuSizeBlock + col_idx / SudokuSizeBlock][k - 1]){
				//设置 k 对应的 validMat
				validMat[0][row_idx][k - 1] = true;
				validMat[1][col_idx][k - 1] = true;
				validMat[2][row_idx / SudokuSizeBlock * SudokuSizeBlock + col_idx / SudokuSizeBlock][k - 1] = true;
				board[row_idx][col_idx] = k + '0';
				if(solveSudoku_dfs(board, row_idx + 1, col_idx)) return true;
				else{
					//探测发现不是合理的选择则重置，继续探测下个数
					validMat[0][row_idx][k - 1] = false;
					validMat[1][col_idx][k - 1] = false;
					validMat[2][row_idx / SudokuSizeBlock * SudokuSizeBlock + col_idx / SudokuSizeBlock][k - 1] = false;
					board[row_idx][col_idx] = '.';
				}  
			}   
		}
	}
	//不合理则返回false
	return false;
}
### 代码
```cpp
const int SudokuSize = 9;
const int SudokuSizeBlock = 3;
bool validMat[3][9][9];

bool solveSudoku_dfs(vector<vector<char>>& board, int row_idx, int col_idx){
	if(row_idx == SudokuSize && col_idx == SudokuSize - 1) return true;
	if(row_idx == SudokuSize) return solveSudoku_dfs(board, 0, col_idx + 1);
	
	if(board[row_idx][col_idx] != '.'){
		return solveSudoku_dfs(board, row_idx + 1, col_idx);
	}
	else{
		for( int k = 1; k <= SudokuSize; k++ ){
			//如果合理
			if(!validMat[0][row_idx][k - 1] && !validMat[1][col_idx][k - 1] && !validMat[2][row_idx/SudokuSizeBlock * SudokuSizeBlock + col_idx / SudokuSizeBlock][k - 1]){
				//设置
				validMat[0][row_idx][k - 1] = true;
				validMat[1][col_idx][k - 1] = true;
				validMat[2][row_idx / SudokuSizeBlock * SudokuSizeBlock + col_idx / SudokuSizeBlock][k - 1] = true;
				board[row_idx][col_idx] = k + '0';
				if(solveSudoku_dfs(board, row_idx + 1, col_idx)) return true;
				else{
					//探测发现不是合理的选择则重置，继续探测下个数
					validMat[0][row_idx][k - 1] = false;
					validMat[1][col_idx][k - 1] = false;
					validMat[2][row_idx / SudokuSizeBlock * SudokuSizeBlock + col_idx / SudokuSizeBlock][k - 1] = false;
					board[row_idx][col_idx] = '.';
				}  
			}   
		}
	}
	//不合理则返回false
	return false;
}

void solveSudoku(vector<vector<char>>& board) {
	
	for( int i = 0; i < 3; i++ ){
		for( int j = 0; j < SudokuSize; j++ ){
			for( int k = 0; k < SudokuSize; k++ ){
				validMat[i][j][k] = false;
			}
		}
	}
	
	for( int i = 0; i < SudokuSize; i++ ){
		for( int j = 0; j < SudokuSize; j++ ){
			//跳过'.'
			if(board[i][j] == '.') continue;
			if(!validMat[0][i][(int)(board[i][j] - '1')] && !validMat[1][j][(int)(board[i][j] - '1')] && !validMat[2][i/SudokuSizeBlock * SudokuSizeBlock + j / SudokuSizeBlock][(int)(board[i][j] - '1')]) {
				validMat[0][i][(int)(board[i][j] - '1')] = true;
				validMat[1][j][(int)(board[i][j] - '1')] = true;
				validMat[2][i/SudokuSizeBlock * SudokuSizeBlock + j / SudokuSizeBlock][(int)(board[i][j] - '1')] = true;
			}
		}
	}
	solveSudoku_dfs(board, 0, 0);
}
```
## 思考与拓展
### 思考
此类问题一般都是DFS。
### 拓展
暂无。


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
