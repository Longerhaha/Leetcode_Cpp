# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 042_(接雨水)Trapping Rain Water
## 问题描述、输入输出与样例

### 问题描述

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。


### 函数输入与输出

* 输入：
	* vector<int>& height：输入每个宽度为 1 的柱子的高度矢量
* 输出：
	* int：下雨后能接的雨水的数目
	
### 问题样例

#### 示例1

输入: [0,1,0,2,1,0,1,3,2,1,2,1]（示意图可见[Leetcode 42 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/description/)）

输出: 6
	
	
## 思路描述与代码	
### 思路描述（左右边界夹击、一遍扫描）
判断宽度为1的柱子 cur_idx 能容纳多少的雨水，他肯定得先看他左方最高的柱子 height[left_max_idx] 和右方的最高的柱子 height[right_max_idx]，
然后得知所能容纳的雨水数目是 min(height[left_max_idx], height[right_max_idx]) - height[cur_idx] > 0 ? min(height[left_max_idx], height[right_max_idx]) - height[cur_idx] : 0。

我们需要利用这种思路构造一遍扫描方法。

```cpp
left 记录左路从左往右搜索的当前位置
right 记录右路从后往前搜索的当前位置
left_max_idx 记录 left 左边的最高的高度下标
right_max_idx 记录 right 右边的最高的高度下标

while( left < right ){
	//如果 height[left_max_idx] < height[right_max_idx] 此时left前进一步，并根据公式计算其能接的水的数目
	if(height[left_max_idx] < height[right_max_idx]){
		left++;
		if(height[left] > height[left_max_idx]) left_max_idx = left;
		else collect_drop += height[left_max_idx] - height[left];
	}
	//否则此时right后退一步，并根据公式计算其能接的水的数目
	else{
		right--;
		if(height[right] > height[right_max_idx]) right_max_idx = right;
		else collect_drop += height[right_max_idx] - height[right];
	}
}
```
### 代码
```cpp
int trap(vector<int>& height) {
	//左右边界一遍扫描法
	int len_height = height.size();
	int left_max_idx = 0, right_max_idx = len_height - 1;
	int left = 0, right = len_height - 1;
	int collect_drop = 0;
	while( left < right ){
		if(height[left_max_idx] < height[right_max_idx]){
			left++;
			if(height[left] > height[left_max_idx]) left_max_idx = left;
			else collect_drop += height[left_max_idx] - height[left];
		}
		else{
			right--;
			if(height[right] > height[right_max_idx]) right_max_idx = right;
			else collect_drop += height[right_max_idx] - height[right];
		}
	}
	return collect_drop;
}
```
## 思考与拓展
### 思考
本题重要的是构造左右边界，这样才能实时算当前点所能接的水的数目，从而实现一遍扫描。
### 拓展
如果给你的是链表数据呢？


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
