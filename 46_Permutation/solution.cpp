#include "../IOLib.hpp"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()) return result;
        sort(nums.begin(), nums.end());
        result.push_back(nums);
        int i = 0, j = 0;
        while(i >= 0){
            i = nums.size() - 2;
            while(i >= 0 && nums[i] >= nums[i+1]) i--;
            if(i < 0) break;
            j = nums.size() - 1;
            while(j > i && nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
            result.push_back(nums);
        }
        return result;
    }
};
