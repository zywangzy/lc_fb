#include "../IOLib.hpp"

/**
Can easily come up with O(n^3) and O(n^2) solutions.
O(n^3): Traverse all combinations of starting and ending indices (i,j)
        where 0 <= i <= j < n, do the sum for each combination and get
        the maximum length.
O(n^2): Do the accumulative sum and store it in an array (O(n)), then
        traverse all combinations (O(n^2)).
Ideal solution in O(n):
        Store accumulative sums in a hashtable, (key, value) pairs are
        sum value and sum ending indecies. Traverse it in one way.
**/
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        dict[0] = -1;
        int sum = 0, maxlen = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(dict.find(sum) == dict.end())
                dict[sum] = i;
            if(dict.find(sum - k) != dict.end())
                maxlen = max(i - dict[sum-k], maxlen);
        }
        return maxlen;
    }
};
