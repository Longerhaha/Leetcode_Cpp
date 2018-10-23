# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 057_(插入区间)Insert Interval
## 问题描述、输入输出与样例

### 问题描述

给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

### 函数输入与输出

* 输入：
	* vector<Interval>& intervals：有序的区间列表
	* Interval newInterval：插入的区间
* 输出：
	* vector<Interval>：插入区间后的区间列表
	
### 问题样例

#### 示例1

输入: intervals = [[1,3],[6,9]], newInterval = [2,5]

输出: [[1,5],[6,9]]
	
#### 示例2
输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]

输出: [[1,2],[3,10],[12,16]]

解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
## 思路描述与代码	
### 思路描述（插入区间并合并区间法）
1. 先将 newInterval 插入 intervals 使其成为一个有序的区间；
2. 合并区间

### 代码
```cpp
static bool compare(const Interval& a, const Interval& b){
	return a.start < b.start;
}
//合并区间
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

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	vector<Interval> ans;
	//intervals 为空
	if(intervals.size() == 0){
		ans.push_back(newInterval);
		return ans;
	}
	
	int start = newInterval.start, end = newInterval.end;
	//先插入区间
	if(newInterval.start >= intervals[intervals.size() - 1].start)
		intervals.push_back(newInterval);
	else{
		for( int i = 0; i < intervals.size(); i++ ){
			if(intervals[i].start > newInterval.start){
				intervals.insert(intervals.begin() + i, newInterval);
				break;
			}
		}
	}
	//合并区间
	return merge(intervals);
}
```
## 思考与拓展
### 思考
本题多一步插入即可。
### 拓展
如果给你无序区间列表，让你求重复的区间呢？
  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
