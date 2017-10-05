#include "../IOLib.hpp"

/**
Time complexity: O(n)
Space complexity: O(n)
**/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            if(map.find(target - nums[i]) != map.end()){
                result[0] = map[target - nums[i]];
                result[1] = i;
                return result;
            }
            map[nums[i]] = i;
        }
    }
};
