/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
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
};