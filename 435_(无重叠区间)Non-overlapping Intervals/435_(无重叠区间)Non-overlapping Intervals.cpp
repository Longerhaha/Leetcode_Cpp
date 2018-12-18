/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

//函数中涉及到的c++知识
//vector<Interval> 是个长度可变的Interval数组，c++里面称为容器
//ret_func_type func(vector<Interval>& name) 中的name是vector<Interval>容器的引用，可以理解为传入一个指针
//sort(g.begin(), g.end(), cmp) 对容器g的Interval元素从小到大排序，容器的起始数据的指针是 g.begin(),容器的末尾数据的指针是g.end()

//按照区间左边界升序排序
bool cmp(const Interval& data1, const Interval& data2){
    return (data1.start < data2.start);
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int cnt_erase = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        //前一个不重复区间的开始与结束
        int start = -1<<31, end = -1<<31;
        for( int i = 0; i < intervals.size(); i++ ){
            //如果两个区间没有重叠
            if(intervals[i].start >= end){
                start = intervals[i].start;
                end   = intervals[i].end;
            }
            //重叠
            else{
                //如果当前区间在区间内，则移除大的区间
                //不在区间内则删除当前区间，这样子删去的区间最少
                if(intervals[i].end <= end){
                    start = intervals[i].start;
                    end   = intervals[i].end;
                }
                cnt_erase++;
            }
        }
        return cnt_erase;
    }
};