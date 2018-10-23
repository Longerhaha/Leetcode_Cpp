# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 055_(跳跃游戏)Jump Game
## 问题描述、输入输出与样例

### 问题描述

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

### 函数输入与输出

* 输入：
	* vector<int>& nums：输入的非负整数数组 nums
* 输出：
	* bool：是否能够到达最后一个位置
	
### 问题样例

#### 示例1

输入: [2,3,1,1,4]

输出: true

解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
	
#### 示例2

输入: [3,2,1,0,4]

输出: false

解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
	
## 思路描述与代码	
### 思路描述（贪心法）
遍历 nums 求最大跳跃距离，然后判断其是否大于等于 nums.size() - 1。
```cpp
max_jump 记录最大跳跃距离
for( i = 0; i < numsSize - 1; i++ ){
	//陷入局部最优则无法继续前进返回 false
	if(i == max_jump && nums[i] == 0) return false;
	else max_jump = max(max_jump, i + nums[i]);
}
return max_jump >= numsSize - 1;
```
### 代码
```cpp
bool canJump(vector<int>& nums) {
	int numsSize = nums.size();
	int max_jump = nums[0];
	for( int i = 0; i < numsSize - 1; i++ ){
		//局部最优
		if(i == max_jump && nums[i] == 0) return false;
		else max_jump = max(max_jump, i + nums[i]);
	}
	return max_jump >= numsSize - 1;
}
```
## 思考与拓展
### 思考
本题需要注意陷入局部最优而无法继续向前跳跃的情况。
### 拓展
暂无想法。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
