# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 045_(跳跃游戏 II)Jump Game II
## 问题描述、输入输出与样例

### 问题描述

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

__说明__:

假设你总是可以到达数组的最后一个位置。

### 函数输入与输出

* 输入：
	* vector<int>& nums：非负整数数组 nums
* 输出：
	* int：最小跳跃距离
	
### 问题样例

#### 示例1

输入: [2,3,1,1,4]

输出: 2

解释: 跳到最后一个位置的最小跳跃数是 2。从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
	
## 思路描述与代码	
### 思路描述（贪心算法）
每一步在 step 内搜索所能跳跃的最大距离，然后跳跃，重复上述过程直到能跳出去。

### 代码
```cpp
int jump(vector<int>& nums) {
	int len_nums = nums.size();
	if(len_nums == 1) return 0;
	int step = 0;
	//当前 step 的 max_distance
	int max_distance = 0 ;
	//当前 step 的 max_distance 内所能跳跃的最大距离
	int cur_step_max_distance = 0;
	for( int i = 0; i < len_nums; i++ ){
		//搜索到当前 step 所能跳跃的最大距离
		if(i == max_distance){
			//跳跃一步，并求出下一步的最大距离
			step++;
			max_distance = max(cur_step_max_distance, i + nums[i]);
			if(max_distance >= len_nums - 1) return step;
		}
		else{
			//搜索当前step范围内的最远距离
			cur_step_max_distance = max(cur_step_max_distance, i + nums[i]);
			if(cur_step_max_distance >= len_nums - 1) return ++step;
		}
	}
}
```
## 思考与拓展
### 思考
本题使用贪心算法，以局部最优推出全局最优。
### 拓展
了解下局部最优和全局最优。


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
