#include "../IOLib.hpp"

/**
Time: O(n)
Space: O(1)
**/

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int target = 0;
        for(int i = 1; i < n; i++){
            if(knows(target, i)) target = i;
        }
        for(int i = 0; i < target; i++){
            if(knows(target, i)) return -1;
        }
        for(int i = 0; i < n; i++){
            if(i != target && !knows(i, target)) return -1;
        }
        return target;
    }
};
