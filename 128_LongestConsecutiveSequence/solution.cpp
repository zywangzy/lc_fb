#include "../IOLib.hpp"

/**
Similar to DFS.
Time: O(n)
Space: O(n)
**/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> dict;
        for(auto n: nums)
            dict.insert(n);
        int maxlen = 0;
        unordered_set<int> visited;
        for(auto it = dict.begin(); it != dict.end(); it++){
            if(visited.find(*it) != visited.end()) continue;
            visited.insert(*it);
            int len = 1, num = *it - 1;
            while(dict.find(num) != dict.end()){
                visited.insert(num);
                num--;
                len++;
            }
            num = *it + 1;
            while(dict.find(num) != dict.end()){
                visited.insert(num);
                num++;
                len++;
            }
            if(len > maxlen) maxlen = len;
        }
        return maxlen;
    }
};
