#include "../IOLib.hpp"

/***
DFS / backtracking.
Time: O(n!)
Space: O(n)
***/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> nums;
        for(int i = 1; i <= n - k + 1; i++){
            nums.push_back(i);
            helper(res, nums, i+1, n, k);
            nums.pop_back();
        }
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& nums, int pos, int n, int k){
        if(nums.size() == k){
            res.push_back(nums);
            return;
        }
        for(int i = pos; i <= n; i++){
            if((n-i+1)<(k-nums.size())) break;
            nums.push_back(i);
            helper(res, nums, i+1, n, k);
            nums.pop_back();
        }
    }
};
