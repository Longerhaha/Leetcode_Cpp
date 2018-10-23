# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 054_(螺旋矩阵)Spiral Matrix
## 问题描述、输入输出与样例

### 问题描述

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

### 函数输入与输出

* 输入：
	* vector<vector<int>>& matrix：输入的矩阵
* 输出：
	* vector<int>：按照顺时针螺旋顺序输出的矩阵元素列表
	
### 问题样例

#### 示例1

输入:

	[
	 [ 1, 2, 3 ],
	 [ 4, 5, 6 ],
	 [ 7, 8, 9 ]
	]
	
输出: [1,2,3,6,9,8,7,4,5]

#### 示例2

输入:

	[
	  [1, 2, 3, 4],
	  [5, 6, 7, 8],
	  [9,10,11,12]
	]
	
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
	
	
## 思路描述与代码	
### 思路描述（圈输出法）

按如下圈的方式添加数据：

			  （上行）
			----------
    left_col|        | right_col
            |        |
            |--------|
			  （下行）
比如：

    [
     [ 1, 2, 3 ],
     [ 4, 5, 6 ],
     [ 7, 8, 9 ]
    ]
	
第一圈添加：上行1,2,3 右列6,9 下行8 左列7,4 
第二圈 5


### 代码
```cpp
void draw_cycle(vector<int> &ans, const vector<vector<int>>& matrix, const int row, const int col, const int center){
	int end_col = center + (col - 2 * center) - 1;
	int end_row = center + (row - 2 * center) - 1;
	for( int i = center; i <= end_col; i++ )
		ans.push_back(matrix[center][i]);
	for( int i = center + 1; i <= end_row; i++ )
		ans.push_back(matrix[i][end_col]);
	//end_row > center 防止当前圈是单行的特殊情况
	for(int i = end_col - 1; i > center && end_row > center; i-- )
		ans.push_back(matrix[end_row][i]);
	//end_col > center 防止当前圈是单列的特殊情况
	for(int i = end_row; i >= center + 1 && end_col > center; i-- )
		ans.push_back(matrix[i][center]);
}
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> ans;
	if(matrix.size() == 0) return ans;
	int row = matrix.size();
	int col = matrix[0].size();
	int len = row * col;
	//转圈的数目
	int circle = 0;
	//中心点(center, center)
	int center = 0;
	while( row >= 2 * circle + 1 && col >= 2 * circle + 1 ){
		draw_cycle(ans, matrix, row, col, center);
		circle++, center++;
	}
	
	return ans;
}
```
## 思考与拓展
### 思考
本题抓住规律和增加判断条件避免一些异常情况即可。
### 拓展
尝试一下[螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii/)。
  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
