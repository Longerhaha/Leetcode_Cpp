# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 074_(搜索二维矩阵)Search a 2D Matrix
## 1 问题描述、输入输出与样例
### 1.1 问题描述
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
* 每行中的整数从左到右按升序排列。
* 每行的第一个整数大于前一行的最后一个整数。
### 1.2 输入与输出
输入：
* vector<vector<int>>& matrix:给定的 m x n 矩阵
* int target:给定的目标值 target

输出：
* bool:在 matrix 中是否存在一个目标值
### 1.3 样例
#### 1.3.1 样例1
输入:<br>
matrix = [<br>
　　[1,   3,  5,  7],<br>
　　[10, 11, 16, 20],<br>
　　[23, 30, 34, 50]<br>
]<br>
target = 3<br>
输出: true <br>
#### 1.3.2 样例2
输入:<br>
matrix = [<br>
　　[1,   3,  5,  7],<br>
　　[10, 11, 16, 20],<br>
　　[23, 30, 34, 50]<br>
]<br>
target = 13<br>
输出: false<br>
## 2 思路描述与代码	
### 2.1 思路描述（行列二分方法）
1. 先在第一列二分查找可能存在的行，准则如下：<br>
中间值若比 target 小，则更新右边界为中间值的前一个下标，否则左边界更新为中间值的下标<br>
二分迭代直到左右边界的距离小于等于1，此时若 target 比右边界大，则可能存在的行为右边界所在的行，否则为左边界所在的行<br>
2. 再二分查找当前行是否存在 target，准则如下：<br>
if 中间值若与 target 相等，则返回 true<br>
else if 中间值若大于 target ，则更新左边界为中间值的下标加1<br>
else 中间值若小于 target ，则更新右边界为中间值的下标减1<br>
迭代上述过程直到左右边界重合，返回此时的值是否与 target 相等<br>

### 2.2 代码
```cpp
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if(m == 0) return false;
    int n = matrix[0].size();
    if(n == 0) return false;
    //二分查找 target 可能所在的行
    int row_start = 0;
    int row_end = m - 1;
    int row = 0;
    while( row_start < row_end - 1 ){
        int row_mid = (row_start + row_end) / 2;
        if(matrix[row_mid][0] > target) row_end = row_mid - 1;
        else row_start = row_mid;
    }
    row = target >= matrix[row_end][0] ? row_end : row_start;
    //二分查找 target 在第 row 行中是否存在
    int col_start = 0, col_end = n - 1;
    while( col_start < col_end ){
        int col_mid = (col_start + col_end) / 2;
        if(matrix[row][col_mid] == target) return true;
        else if(matrix[row][col_mid] > target) col_end = col_mid - 1;
        else col_start = col_mid + 1;
    }
    return matrix[row][col_start] == target;
}
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
#### 3.1.1.1 暴力查找法
遍历所有元素，看是否存在 target。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
暴力查找法|O(1)|O(n^2)
行列二分法|O(1)|O(nlogn)
#### 3.1.3 难点分析
1. 查找可能存在的行
### 3.2 拓展
如果让你查找三维有序张量呢？
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
