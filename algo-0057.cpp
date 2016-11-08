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
       
       int s = findStart(intervals, newInterval);
       int e = findEnd(intervals, newInterval);
       
       // pack up
       vector<Interval> ret;
       for(int i = 0; i < s; i++) ret.push_back(intervals[i]);
       if (s < len)
            newInterval.start = min(newInterval.start, intervals[s].start);
       if (e >= 0)
            newInterval.end = max(newInterval.end, intervals[e].end);
       ret.push_back(newInterval);
       for(int i = e + 1; i < len; i++) ret.push_back(intervals[i]);
       return ret;
    }
private:
    int findStart(vector<Interval>& intervals, Interval newInterval){
        int len = intervals.size(), hi = len - 1, lo = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            int end = intervals[mid].end;
            if (end == newInterval.start){
                return mid;
            } else if (end > newInterval.start){
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo; // intervals[lo] > target, argmin lo
    }
    int findEnd(vector<Interval>& intervals, Interval newInterval){
        int len = intervals.size(), hi = len - 1, lo = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            int start = intervals[mid].start;
            if (start == newInterval.end){
                return mid;
            } else if (start > newInterval.end){
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return hi; // intervals[hi] < target, argmax hi
    }
};
