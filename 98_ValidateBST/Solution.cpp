#include "../IOLib.hpp"

/***
This is inorder traverse. Could also get all the value ranges for each
subtree and check if ranges are alright.
Time: O(n)
Space: O(n)
***/

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
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        if(!inorder_traverse(root, nums)) return false;
        return true;
    }
    bool inorder_traverse(TreeNode* root, vector<int>& nums){
        if(!root) return true;
        if(!inorder_traverse(root->left, nums)) return false;
        if(!nums.empty() && nums.back() >= root->val) return false;
        nums.push_back(root->val);
        if(!inorder_traverse(root->right, nums)) return false;
        return true;
    }
};
