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
             ---------|
    left_col |        | right_col
             |---------
              （下行）
			  
比如：

    [
     [ 1, 2, 3 ],
     [ 4, 5, 6 ],
     [ 7, 8, 9 ]
    ]
	
第一圈添加：上行1,2 右列3,6 下行9,8 左列7,4 第二圈 5


### 代码
```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> ans;
	if(matrix.size() == 0) return ans;
	int row = matrix.size();
	int col = matrix[0].size();
	int len = row * col;
	//转圈的数目
	int circle = 1;
	//每圈开始的中心位置
	int r0 = 0, c0 = 0;
	int cnt = 0;
	while( cnt < len ){
		//每次转圈上行和下行走动的步数
		int row_size = col + 1 - circle * 2;
		//每次转圈左列和右列走动的步数
		int col_size = row + 1 - circle * 2;
		//只剩一个中心点
		if(row_size == 0 && col_size == 0){
			ans.push_back(matrix[r0][c0]);
			cnt++;
		}
		else{
			//上行
			for( int i = 0; i < row_size && cnt < len; i++ )
				cnt++, ans.push_back(matrix[r0][c0 + i]);
			//右列
			for( int j = 0; j < col_size && cnt < len; j++ )
				cnt++, ans.push_back(matrix[r0 + j][c0 + row_size]);
			//下行
			for( int i = row_size; i > 0 && cnt < len; i-- )
				cnt++, ans.push_back(matrix[r0 + col_size][c0 + i]);
			//左列
			for( int j = col_size; j > 0 && cnt < len; j-- )
				cnt++, ans.push_back(matrix[r0 + j][c0]);
			r0++, c0++, circle++;
		} 
	}
	return ans;
}
```
## 思考与拓展
### 思考
本题抓住规律和不要超过矩阵所有元素的数目即可避免一些异常情况。
### 拓展
尝试一下[螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii/)。
  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
