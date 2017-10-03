#include "../IOLib.hpp"

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
private:
/**
This is for comparison of Intervals in vector.
**/
    static bool cmp(Interval& i1, Interval& i2){
        return i1.start < i2.start;
    };
/**
This is for comparison of elements in priority_queue.
**/
    class compare{
    public:
        bool operator() (int a, int b) const{
            return a > b;
        }
    };
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, compare> pq; //Don't forget pq's format!
        int rooms = 0;
        for(auto interval: intervals){
            while(!pq.empty() && pq.top() <= interval.start)
                pq.pop();
            pq.push(interval.end);
            if(pq.size() > rooms) rooms = pq.size();
        }
        return rooms;
    }
};
