# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 018_(四数之和)4Sum
## 问题描述、输入输出与样例

### 问题描述
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

__注意__：

答案中不可以包含重复的四元组。


### 函数输入与输出

* 输入：
	* vector<int>& nums：给定包含 n 个整数的数组 nums
	* int target：目标值
* 输出：
	* vector<vector<int>>：四元组列表，每一个列表元素都是一个四个数的列表
	
### 问题样例

#### 示例1

输入: nums = [1, 0, -1, 0, -2, 2]，和 target = 0

输出:

	[
	  [-1,  0, 0, 1],
	  [-2, -1, 1, 2],
	  [-2,  0, 0, 2]
	]

	
## 思路描述与代码	
### 思路描述（双指针法）
首先第一步排序；

其次遍历所有的元素 x ，然后利用[三数之和](https://github.com/Longerhaha/Leetcode_Cpp/tree/master/015_(%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C)3Sum)的方法去查找 target - x。

### 代码
```cpp
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	int len = nums.size();
	for( int i = 0; i < len; i++ ){
		//四数和去重
		if(i - 1 >= 0 && nums[i] == nums[i - 1])
			continue;
		int threeSum = target - nums[i];
		for( int j = i + 1; j < len; j++ ){
			//三数和去重
			if(j > i + 1 && nums[j] == nums[j - 1])
				continue;
			else{
				int two_sum = threeSum - nums[j];
				int start = j + 1;
				int end = len - 1;
				while( start < end ){
					if(nums[start] + nums[end] == two_sum){
						ans.push_back({nums[i], nums[j], nums[start], nums[end]});
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
	}
	return ans;
}
```
## 思考与拓展
### 思考
本题从三数之和改过来即可，时间复杂度为O(n^3)。
### 拓展
如果让你求四数最近和呢？和三数最近和道理一样。


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
