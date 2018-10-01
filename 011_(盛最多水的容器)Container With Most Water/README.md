# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 011_(盛最多水的容器)Container With Most Water
## 问题描述、输入输出与样例

### 问题描述

给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。

在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

### 函数输入与输出

* 输入：
	* vector<int>& height：输入的高度数组
* 输出：
	* int：可以容纳最多的水
	
### 问题样例

#### 示例1

输入: [1,8,6,2,5,4,8,3,7]

输出: 49

解释：两条线为子数组[8,6,2,5,4,8,3,7]的起始于终点位置
	
	
## 思路描述与代码	
### 思路描述（双指针法）

start 指向高度数组的起始位置，end 指向高度数组的结束位置， max_area 记录容器可以容纳最多的水

while( start < end ){
	算出当前 start 与 end 位置x 轴共同构成的容器可以容纳最多水，如果比 max_area 大则更新其值；
	如果 start 位置的高度比 end 位置的高度小，则需要将 start 位置前进一步，否则 end 退后一步
}
	


### 代码

	int maxArea(vector<int>& height) {
        int height_len = height.size();
        int start = 0;
        int end = height_len - 1;
        int max_area = 0;
        while( start < end ){
            max_area = max(max_area, min(height[start], height[end]) * (end - start));
            //更新 start 和 end
            if(height[start] < height[end])
                start++;
            else end--;
        }
        return max_area;
    }
 
## 思考与拓展
### 思考
双指针法的时间复杂度为O（n），如果用暴力解题法则是O（n^2）。
### 拓展



	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
