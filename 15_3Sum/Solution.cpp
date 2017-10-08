#include "../IOLib.hpp"

/**
Time: O(n^2)
Space: O(1)
**/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1, sum;
            while(left < right){
                sum = nums[left] + nums[right];
                if(sum == target){
                    result.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(right > left && nums[right] == nums[right - 1]) right--;
                    left++; right--;
                }
                else if(sum < target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return result;
    }
};
