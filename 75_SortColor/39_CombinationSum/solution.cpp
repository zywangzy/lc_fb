#include "../IOLib.hpp"

/**
Time: O(n^m)
Space: O(n^m)
**/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> nums;
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        for(int i = 0; i < candidates.size(); i++){
            nums.push_back(candidates[i]);
            sum += nums.back();
            dfs(res, candidates, nums, sum, i, target);
            sum -= nums.back();
            nums.pop_back();
        }
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& candidates, vector<int>& cur, int sum, int pos, int target){
        if(sum > target) return;
        if(sum == target){
            res.push_back(cur);
            return;
        }
        //sum < target
        for(int i = pos; i < candidates.size(); i++){
            cur.push_back(candidates[i]);
            sum += cur.back();
            if(sum > target){
                sum -= cur.back();
                cur.pop_back();
                break;
            }
            dfs(res, candidates, cur, sum, i, target);
            sum -= cur.back();
            cur.pop_back();
        }
        
    }
};
