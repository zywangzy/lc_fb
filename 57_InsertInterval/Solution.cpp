#include "../IOLib.hpp"

/***
Time: O(n)
Space: O(n) (including result)
Could use lower_bound(intervals.begin(), intervals.end(), newInterval, cmp) function
to do binary search for the first place to merge.
***/

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
        if(intervals.empty()){
            intervals.push_back(newInterval);
            return intervals;
        }
        //Initially sorted
        vector<Interval> res;
        bool in = false;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i].end < newInterval.start){
                res.push_back(intervals[i]);
            }
            else if(intervals[i].start <= newInterval.end){
                if(intervals[i].start < newInterval.start)
                    newInterval.start = intervals[i].start;
                if(newInterval.end < intervals[i].end)
                    newInterval.end = intervals[i].end;
            }
            else{
                if(!in){
                    res.push_back(newInterval);
                    in = true;
                }
                res.push_back(intervals[i]);
            }
        }
        if(!in) res.push_back(newInterval);
        return res;
    }
};
