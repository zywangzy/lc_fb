#include "../IOLib.hpp"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> nums;
        for(int i = 1; i <= 9; i++){
            nums.push_back(i);
            backtrack(res, nums, i+1, i, k, n);
            nums.pop_back();
        }
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int pos, int sum, int k, int n){
        if(nums.size() == k){
            if(sum == n) res.push_back(nums);
            return;
        }
        if(sum > n) return;
        for(int i = pos; i <= 9; i++){
            if(sum + i > n) break;
            nums.push_back(i);
            backtrack(res, nums, i+1, sum + i, k, n);
            nums.pop_back();
        }
    }
};
