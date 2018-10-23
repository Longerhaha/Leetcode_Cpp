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
};