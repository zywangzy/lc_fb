#include "../IOLib.hpp"

/**
Binary search.
Time: O(log(n))
Space: O(1)
**/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 0) return false;
        if(num <= 1) return true;
        int l = 1, r = num / 2;
        while(l <= r){
            long mid = l + (r - l) / 2;
            if(mid * mid == num) return true;
            else if(mid * mid < num){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return false;
    }
};
