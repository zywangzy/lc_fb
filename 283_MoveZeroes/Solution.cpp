#include "../IOLib.hpp"

class Solution {
public:
/*
Time complexity: O(n)
Space complexity: O(1)
*/
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        for( ; i < nums.size(); i++){
            if(nums[i])
                nums[j++] = nums[i];
        }
        for( ; j < nums.size(); j++)
            nums[j] = 0;
    }
};

class Solution {
public:
/*
Time complexity: O(n)
Space complexity: O(1)
This solution is better because its operation number is less.
*/
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        for( ; i < nums.size(); i++){
            if(nums[i]){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
