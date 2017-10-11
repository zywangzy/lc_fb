#include "../IOLib.hpp"

/**
Use hashset.
Time: O(n1 + n2)
Space: O(n1)
**/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> dict(nums1.begin(), nums1.end());
        vector<int> res;
        for(auto n: nums2){
            if(dict.find(n) != dict.end()){
                res.push_back(n);
                dict.erase(n);
            }
        }
        return res;
    }
};
