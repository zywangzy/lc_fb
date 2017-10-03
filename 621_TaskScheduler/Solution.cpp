#include "../IOLib.hpp"

/**
Time complexity: O(len(tasks))
Space complexity: O(1) (int[26])
Better not to use map if the number of entries are small.
Just an array is much faster.
**/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //unordered_map<char, int> counts;
        int counts[26] = {0};
        int maxcount = 0, times = 0;
        for(auto c: tasks){
            counts[c-'A']++;
            if(counts[c-'A'] > maxcount){
                maxcount = counts[c-'A'];
                times = 1;
            }
            else if(counts[c-'A'] == maxcount){
                times++;
            }
        }
        return max((maxcount - 1) * (n + 1) + times, (int)tasks.size());
    }
};
