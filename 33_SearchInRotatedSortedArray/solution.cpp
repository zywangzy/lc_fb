#include "../IOLib.hpp"

/**
Time: O(log(n))
Space: O(1)
This time used bias to calculate new index relative to pivot point. Therefore
have 2 rounds of binary search (pivot position and target value).
Could also just do 1 round and search directly using binary search.
**/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len < 1) return -1;
        int left = 0, right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[left] < nums[mid]){
                left = mid;
            }
            else{
                right = mid - 1;
            }
        }
        int pivot = left + 1;
        left = 0, right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            int proxy = (mid + pivot) % len;
            if(nums[proxy] == target) return proxy;
            else if(target < nums[proxy]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        if(nums[(left + pivot) % len] == target) return (left + pivot) % len;
        return -1;
    }
};
