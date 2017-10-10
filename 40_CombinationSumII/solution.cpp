#include "../IOLib.hpp"

/***
Change ">=" to ">". Added duplicate checking.
***/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> nums;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        for(int i = 0; i < candidates.size(); i++){
            if(candidates[i] > target) break;
            if(i > 0 && candidates[i] == candidates[i-1]) continue;
            nums.push_back(candidates[i]);
            sum += nums.back();
            backtrack(res, candidates, nums, sum, i + 1, target);
            sum -= nums.back();
            nums.pop_back();
        }
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& candidates, vector<int>& nums, int sum, int pos, int target){
        if(sum >= target){
            if(sum == target) res.push_back(nums);
            return;
        }
        for(int i = pos; i < candidates.size(); i++){
            if(sum + candidates[i] > target) break;
            if(i > pos && candidates[i] == candidates[i-1]) continue;
            nums.push_back(candidates[i]);
            backtrack(res, candidates, nums, sum + candidates[i], i+1, target);
            nums.pop_back();
        }
    }
};
