#include "../IOLib.hpp"

/***
3 Ways:
1. Recursive BFS.
2. Recursive DFS.
3. Iterative BFS.
This is method #2.
Time: O(2^n)
Space: O(n)
***/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> seed;
        dfs(res, seed, nums, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& seed,
             vector<int>& nums, int pos){
        if(pos == nums.size()){
            res.push_back(seed);
            return;
        }
        dfs(res, seed, nums, pos+1);
        seed.push_back(nums[pos]);
        dfs(res, seed, nums, pos+1);
        seed.pop_back();
    }
};
