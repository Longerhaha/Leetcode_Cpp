# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 015_(三数之和)3Sum
## 问题描述、输入输出与样例

### 问题描述

给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

__注意__：答案中不可以包含重复的三元组。

### 函数输入与输出

* 输入：
	* vector<int>& nums：给定的包含 n 个整数的数组 nums
* 输出：
	* vector<vector<int>>：三数之和为0的所有不重复答案列表，其中每个答案也是一个列表
	
### 问题样例

#### 示例1

输入: nums = [-1, 0, 1, 2, -1, -4]

输出:

	[
	  [-1, 0, 1],
	  [-1, -1, 2]
	]
	
## 思路描述与代码	
### 思路描述（双指针法）
首先第一步排序；

其次遍历所有的元素 x 
* 若其与上一个元素重复则跳过该循环
* 否则利用双指针法查找在 x 位置之后且和为 -x 的两个数（就是2SUM，注意去重）

### 代码
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	int len = nums.size();
	for( int i = 0; i < len; i++ ){
		//三数和去重
		if(i - 1 >= 0 && nums[i] == nums[i - 1])
			continue;
		else{
			int two_sum = -nums[i];
			int start = i + 1;
			int end = len - 1;
			while( start < end ){
				if(nums[start] + nums[end] == two_sum){
					ans.push_back({nums[i], nums[start], nums[end]});
					//二数和去重
					while(start < end && nums[start] == nums[start + 1]) start++;
					while(start < end && nums[end] == nums[end - 1]) end--;
					start++, end--;
				}
				else if(nums[start] + nums[end] < two_sum) start++;
				else end--;
			}
		}
	}
	return ans;
}
```
 
 
## 思考与拓展
### 思考
本题的解法的时间复杂度为O（n^2），且利用双指针法而不是哈希表法可以降低空间复杂度。

顺便提一下在2SUM中使用双指针法为什么不是时间复杂度最低的算法。在2SUM中使用双指针法的前提是要先排序，
然而排序时间复杂度为O（nlogn），此时时间复杂度主要在排序，如果使用哈希表法可以获得最低的时间复杂度O（n）。

### 拓展
如果四数之和呢？最低时间复杂度可以到多少？


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
