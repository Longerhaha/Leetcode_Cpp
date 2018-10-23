# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 056_(合并区间)Merge Intervals
## 问题描述、输入输出与样例

### 问题描述

给出一个区间的集合，请合并所有重叠的区间。

### 函数输入与输出

* 输入：
	* vector<Interval>& intervals：区间的集合列表
* 输出：
	* vector<Interval>：合并后的区间列表
	
### 问题样例

#### 示例1

输入: [[1,3],[2,6],[8,10],[15,18]]

输出: [[1,6],[8,10],[15,18]]

解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].：

#### 示例2

输入: [[1,4],[4,5]]

输出: [[1,5]]

解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
	
## 思路描述与代码	
### 思路描述（区间关系判断法）
先根据区间的左边界 来排序；

区间与区间之间的关系主要分为三种：
1. 相容
2. 相交
3. 相斥

对其处理的代码如下：
```cpp
不妨记当前的区间的开始点为 start， 结束点为 end
对 intervals[i] 有：
for( i = 0; i < intervals.size(); i++ ){
	//相容
	if(start <= intervals[i].start && end >= intervals[i].end) continue;
	//相交
	else if(end >= intervals[i].start) end = intervals[i].end;
	//相斥
	else{
		ans.push_back(Interval(start, end));
		start = intervals[i].start;
		end = intervals[i].end;
	}
}
ans.push_back(Interval(start, end));
```

### 代码
```cpp
static bool compare(const Interval& a, const Interval& b){
	return a.start < b.start;
}
vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> ans;
	if(intervals.size() == 0) return ans;
	sort(intervals.begin(), intervals.end(), compare);
	int start = intervals[0].start, end = intervals[0].end;
	for( int i = 0; i < intervals.size(); i++ ){
		//相容
		if(start <= intervals[i].start && end >= intervals[i].end) continue;
		//相交
		else if(end >= intervals[i].start) end = intervals[i].end;
		//相斥
		else{
			ans.push_back(Interval(start, end));
			start = intervals[i].start;
			end = intervals[i].end;
		}
	}
	ans.push_back(Interval(start, end));
	return ans;
}
```
## 思考与拓展
### 思考
本题主要理解区间与区间的关系，不难。
### 拓展
如果让你[插入区间](https://leetcode-cn.com/problems/insert-interval/)呢？
  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
