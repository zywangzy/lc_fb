#include "../IOLib.hpp"

/**
Divide and conquer.
Time: O(n)
Space: O(log(n))
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return builder(nums, 0, nums.size()-1);
    }
    TreeNode* builder(vector<int>& nums, int l, int r){
        if(l > r) return NULL;
        if(l == r) return new TreeNode(nums[l]);
        int mid = l + (r - l) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = builder(nums, l, mid - 1);
        node->right = builder(nums, mid + 1, r);
        return node;
    }
};
