# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 048_(旋转图像)Rotate Image
## 问题描述、输入输出与样例

### 问题描述

给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

### 函数输入与输出

* 输入：
	* vector<vector<int>>& matrix：输入图像的二维矩阵
* 输出：
	* void：原地修改
	
### 问题样例

#### 示例1

输入: 

	[
	  [1,2,3],
	  [4,5,6],
	  [7,8,9]
	]
	
输出:

	[
	  [7,4,1],
	  [8,5,2],
	  [9,6,3]
	]
	
#### 示例2

输入: 

	[
	  [ 5, 1, 9,11],
	  [ 2, 4, 8,10],
	  [13, 3, 6, 7],
	  [15,14,12,16]
	]
	
输出:

	[
	  [15,13, 2, 5],
	  [14, 3, 4, 1],
	  [12, 6, 8, 9],
	  [16, 7,10,11]
	]
	
	
## 思路描述与代码	
### 思路描述（两步原地修改法）

1. 第一步交换交叉项

	比如交换交叉项 matrix[i][j], matrix[col_size - 1 - j][row_size - 1 - i]：
	[
	  [1,2,3],
	  [4,5,6],
	  [7,8,9]
	]
	第一步原地修改后：
	[
	  [9,6,3],
	  [8,5,2],
	  [7,4,1]
	]

2. 第二步交换前后行
	
	第0行与第2行交换，即将
	[
	  [9,6,3],
	  [8,5,2],
	  [7,4,1]
	]
	交换后为：
	[
	  [7,4,1],
	  [8,5,2],
	  [9,6,3]
	]


### 代码
```cpp
void rotate(vector<vector<int>>& matrix) {
	int row_size = matrix.size();
	int col_size = matrix[0].size();
	
	//中间步
	//交换交错项 matrix[i][j], matrix[col_size - 1 - j][row_size - 1 - i]
	for( int i = 0; i < row_size - 1; i++ ){
		for( int j = 0; j < col_size - i - 1; j++ ){
			swap(matrix[i][j], matrix[col_size - 1 - j][row_size - 1 - i]);
		}
	}
	//前后交换行
	for( int i = 0; i < row_size / 2; i++ ){
		for( int j = 0; j < col_size; j++ ){
			swap(matrix[i][j], matrix[row_size - i - 1][j]);
		}
	} 
}
```
## 思考与拓展
### 思考
本题要实现一步原地修改还是不大可能的，分解为两步之后就很简单了。
### 拓展
如果给你的是一个非方阵呢？可以了解下图像处理里面旋转时需要考虑的一些元素。


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
