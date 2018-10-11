# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 031_(下一个排列)Next Permutation
## 问题描述、输入输出与样例

### 问题描述

实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

### 函数输入与输出

* 输入：
	* 
* 输出：
	* 
	
### 问题样例

#### 示例1

输入:1,2,3 

输出:1,3,2

#### 示例2
	
输入:3,2,1

输出:1,2,3

#### 示例3
	
输入:1,1,5

输出:1,5,1
		
## 思路描述与代码	
### 思路描述（排列树结构法）
回溯法的解空间有基于排列树的解空间，下一个排列就是下一棵排列树的解空间，所以可以根据排列树的结构来解这道题。

主要有三个步骤：

1.寻根：从最后第二个元素逆序找，找到 nums[root_idx + 1] > nums[root_idx] 的下标；

2.交换：从尾巴开始找，直到找到比 nums[root_idx] 大的数，然后交换二者的值；

3.反序：将 nums[root_idx] nums[root_idx + 1] ... nums[len - 1] 反序。

### 代码
```cpp
void nextPermutation(vector<int>& nums) {
	int len = nums.size();
	//找根
	int root_idx;
	for( root_idx = len - 2; root_idx >= 0; root_idx-- ){
		if(nums[root_idx + 1] > nums[root_idx]) break;
	}
	//本身就是逆序的，即没有下一个更大的排列
	if(root_idx == -1 || len == 0) return reverse(nums.begin(), nums.end());
	
	//从尾巴开始找，直到找到比 nums[root_idx] 大的数，然后交换二者的值
	for( int i = len - 1; i > root_idx; i-- ){
		if(nums[i] > nums[root_idx]){
			swap(nums[i], nums[root_idx]);
			break;
		}
	}
	//将 nums[root_idx] nums[root_idx + 1] ... nums[len - 1] 反序
	reverse(nums.begin() + root_idx + 1, nums.end());
}
```
## 思考与拓展
### 思考
本题重要的理解排列树的结构特点。
### 拓展
如果让你求上一个排列呢？


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
