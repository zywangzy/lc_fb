#include "../IOLib.hpp"

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left < right){
            int mid = left + (right - left) / 2;
            // note that "mid = (left + right) / 2" might overflow.
            if(isBadVersion(mid)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};
