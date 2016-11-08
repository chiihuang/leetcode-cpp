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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
       int len = intervals.size(), hi = len, lo = 0;
       
       // find start
       while(lo < hi){
           int mid = lo + (hi - lo) / 2;
           if (intervals[mid].end >= newInterval.start){
               hi = mid;
           } else {
               lo = mid + 1;
           }
       }
       
       int s = lo;
       hi = len - 1;
       lo = -1;
       while(lo < hi){
           int mid = lo + (hi - lo + 1) / 2;
           if (intervals[mid].start <= newInterval.end){
               lo = mid; // todo
           } else {
               hi = mid - 1;
           }
       }
       int e = lo;
       
       // pack up
       vector<Interval> ret;
       for(int i = 0; i < s; i++){
           ret.push_back(intervals[i]);
       }
       if (s < len)
            newInterval.start = min(newInterval.start, intervals[s].start);
       if (e >= 0)
            newInterval.end = max(newInterval.end, intervals[e].end);
       ret.push_back(newInterval);
       for(int i = e + 1; i < len; i++){
           ret.push_back(intervals[i]);
       }
       return ret;
    }
};
