# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 059_(螺旋矩阵 II)Spiral Matrix II
## 问题描述、输入输出与样例

### 问题描述

给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

### 函数输入与输出

* 输入：
	* int n：生成一个包含 1 到 n^2 所有元素
* 输出：
	* vector<vector<int>>：按照顺时针螺旋生成的n * n矩阵
	
### 问题样例

#### 示例1

输入: 3
	
输出: 

	[
	 [ 1, 2, 3 ],
	 [ 4, 5, 6 ],
	 [ 7, 8, 9 ]
	]

#### 示例2

## 思路描述与代码	
### 思路描述（圈计数法）

按如下圈的方式添加数据：

			  （上行）
			----------
    left_col|        | right_col
            |        |
            |--------|
			  （下行）
比如：输入 n = 3
	
第一圈生成：

	1 2 3
	8   4
	7 6 5
	
	
第二圈生成9，即：
	
	1 2 3
	8 9 4
	7 6 5


### 代码
```cpp
void draw_cycle(vector<vector<int>>& matrix, const int size, const int center, int& cnt){
	int end_col = center + (size - 2 * center) - 1;
	int end_row = center + (size - 2 * center) - 1;
	for( int i = center; i <= end_col; i++ )
		matrix[center][i] = ++cnt;
	for( int i = center + 1; i <= end_row; i++ )
		matrix[i][end_col] = ++cnt;
	//end_row > center 防止当前圈是单行的特殊情况
	for(int i = end_col - 1; i > center && end_row > center; i-- )
		matrix[end_row][i] = ++cnt;
	//end_col > center 防止当前圈是单列的特殊情况
	for(int i = end_row; i >= center + 1 && end_col > center; i-- )
		matrix[i][center] = ++cnt;
}
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	if(n == 0) return matrix;
	int total_len = n * n;
	//转圈的数目
	int circle = 0;
	//中心点(center, center)
	int center = 0;
	int cnt = 0;
	while( n >= 2 * circle + 1 && n >= 2 * circle + 1 ){
		draw_cycle(matrix, n, center, cnt);
		circle++, center++;
	}
	return matrix;
}
```
## 思考与拓展
### 思考
本题只需在[54 螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/)修改即可，思路基本一致。
### 拓展
1. 如果本题输入 row、 col， 让你生成 row * col 的矩阵呢？
2. 尝试一下[螺旋矩阵 III](https://leetcode-cn.com/problems/spiral-matrix-iii/)。
  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
