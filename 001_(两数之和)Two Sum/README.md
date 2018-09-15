# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 001_(两数之和)Two Sum
## 问题描述、样例与输入输出

### 问题描述

给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

### 问题样例

	示例1:
	输入: 
	nums = [2, 7, 11, 15], target = 9
	  
	输出: 
	[0, 1]
	
	解释：
	因为 nums[0] + nums[1] = 2 + 7 = 9
	
### 函数输入与输出

* 输入：
	* vector<int>& nums：输入一维数据的引用
	* int target：目标
* 输出：
	* vector<int>：和为target的两个数的下标

## 思路	
### 哈希表

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> map;
        for( int i = 0; i < nums.size(); i++ ){
            //如果另外一个之前出现过，则找到了
            if(map.count(target - nums[i]) > 0){
                ans.push_back(map[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            //否则记录在哈希表内
            else{
                map[nums[i]] = i;
            }
        }
        
        //都没有找到
        return ans;
    }

 
## 拓展与思考：
### 拓展
如果是三数之和呢？
### 思考
本题，哈希表可以实现O(n)的复杂度。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
