# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 885_螺旋矩阵 III
## 问题描述、样例与输入输出

### 问题描述

在 R 行 C 列的矩阵上，我们从 (r0, c0) 面朝东面开始

这里，网格的西北角位于第一行第一列，网格的东南角位于最后一行最后一列。

现在，我们以顺时针按螺旋状行走，访问此网格中的每个位置。

每当我们移动到网格的边界之外时，我们会继续在网格之外行走（但稍后可能会返回到网格边界）。

最终，我们到过网格的所有 R * C 个空间。

按照访问顺序返回表示网格位置的坐标列表。


### 问题样例

	示例1:
	输入: 
	R = 1, C = 4, r0 = 0, c0 = 0
	输出: 
	[[0,0],[0,1],[0,2],[0,3]]
	
	示例2:
	输入: 
	R = 5, C = 6, r0 = 1, c0 = 4
	输出: 
	[[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
	
	解释：
	上面两个实例的图解可以查看[此处](https://leetcode-cn.com/contest/weekly-contest-97/problems/spiral-matrix-iii/)
	
### 函数输入与输出

* 输入：
	* int R: 螺旋矩阵的行数 
	* int C: 螺旋矩阵的列数
	* int r0: 螺旋矩阵的中心点的行数
	* int c0: 螺旋矩阵的中心点的列数
* 输出：
	* vector<vector<int>>：螺旋矩阵遍历的二维矢量

## 思路	
### 扩张法

	//扩张的方式(比如size为2)
    //分四个方向扩张
    //                | --- ---
    //                |   c   |
    //                 --- ---|
    //
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        ans.push_back({r0, c0});
        //扩张的步长
        int step = 2;
        int col, row;
        while(ans.size() < R * C){
            //右反纵向扩张
            col = c0 + 1;
            for( row = r0; row < r0 + step; row++ ){
                if(row >= 0 && row < R && col >= 0 && col < C){
                    ans.push_back({row, col});
                }
            }
            //下反横向扩张
            row = r0 + step - 1;
            for( col = c0; col > c0 - step; col-- ){
                if(row >= 0 && row < R && col >= 0 && col < C){
                    ans.push_back({row, col});
                }
            }
            //左反纵向扩张
            col = c0 - step + 1;
            for( row = r0 + step - 2; row >= r0 - 1; row-- ){
                if(row >= 0 && row < R && col >= 0 && col < C){
                    ans.push_back({row, col});
                }
            }
            //上横向扩张
            row = r0 - 1;
            for( col = c0 - step + 2; col <= c0 + 1; col++ ){
                if(row >= 0 && row < R && col >= 0 && col < C){
                    ans.push_back({row, col});
                }
            }
            //步长加2，并移动中心点，为下次扩张做好准备
            step += 2;
            r0 = r0 - 1;
            c0 = c0 + 1;
            //cout << ans.size() << endl;
        }
        
        return ans;
    }
		

 
## 拓展与思考：
### 拓展
暂无想法。
### 思考
本题相比于螺旋矩阵、螺旋矩阵II更具有挑战性，但思路还是一致。	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
