#include "../IOLib.hpp"

/**
Use a min-heap to store the K largest numbers.
Time: O(nlog(k))
Space: O(k)
**/

class cmp{
public:
    bool operator()(int a, int b){
        return a > b;
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, cmp> pq;
        for(int i = 0; i < k; i++)
            pq.push(nums[i]);
        for(int i = k; i < nums.size(); i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

/**
Could also use a quick-select algorithm to do the partition.
Time: On average, O(n), but in worst case, O(n^2)
Space: O(1)
**/
