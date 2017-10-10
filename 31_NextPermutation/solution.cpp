#include "../IOLib.hpp"

/***
Find the first one smaller than next one, then swap it with the first one
larger than it.
Time: O(n)
Space: O(1)
***/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;
        int i = nums.size() - 2;
        while(i >= 0){
            if(nums[i] < nums[i+1]){
                break;
            }
            i--;
        }
        if(i >= 0){
            int j = nums.size() - 1;
            while(j > i){
                if(nums[j] > nums[i]){
                    break;
                }
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
