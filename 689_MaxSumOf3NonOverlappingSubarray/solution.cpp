#include "../IOLib.hpp"

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> sums(nums.size() - k + 1, 0);
        vector<int> leftmax(nums.size() - k + 1, 0), rightmax(nums.size() - k + 1, nums.size() - k);
        for(int i = 0; i < k; i++){
            sums[0] += nums[i];
        }
        int tot = sums[0];
        for(int i = 1; i < sums.size(); i++){
            sums[i] = sums[i - 1] + nums[i + k - 1] - nums[i - 1];
            if(sums[i] > tot){
                tot = sums[i];
                leftmax[i] = i;
            }
            else leftmax[i] = leftmax[i-1];
        }
        tot = sums.back();
        for(int i = sums.size() - 1; i >= 0; i--){
            if(sums[i] >= tot){
                tot = sums[i];
                rightmax[i] = i;
            }
            else rightmax[i] = rightmax[i+1];
        }
printVector(sums);
printVector(leftmax);
printVector(rightmax);
        tot = 0;
        int end = nums.size() - 2 * k;
        vector<int> res;
        for(int i = k; i <= end; i++){
            int s = sums[i] + sums[leftmax[i - k]] + sums[rightmax[i + k]];
            if(s > tot){
                tot = s;
                res = {leftmax[i-k], i, rightmax[i+k]};
            }
        }
        return res;
    }
};

int main(void){
    vector<int> nums;
    readVector(nums);
    int k = readInt();
    Solution sol;
    vector<int> res = sol.maxSumOfThreeSubarrays(nums, k);
    printVector(res);
    return 0;
}
