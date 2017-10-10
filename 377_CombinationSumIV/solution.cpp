#include "../IOLib.hpp"

/**
DP.
Time: O(n*t)
Space: O(t)
**/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(auto num: nums){
                if(num > i) break;
                dp[i] += dp[i - num];
            }
        }
        return dp.back();
    }
};
