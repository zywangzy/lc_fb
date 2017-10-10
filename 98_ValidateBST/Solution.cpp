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


/***
This is bottom-up method, there're also top-down method.
Time: O(n)
Space: O(h)
***/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        pair<int, int> range;
        return valid(root, range);
    }
    bool valid(TreeNode* root, pair<int, int>& range){
        if(!root) return true;
        if(!root->left && !root->right){
            range.first = root->val;
            range.second = root->val;
            return true;
        }
        pair<int, int> lrange, rrange;
        if(root->left){
            if(!valid(root->left, lrange)) return false;
            if(lrange.first >= root->val || lrange.second >= root->val) return false;
            range.first = lrange.first;
        }
        else range.first = root->val;
        if(root->right){
            if(!valid(root->right, rrange)) return false;
            if(rrange.first <= root->val || rrange.second <= root->val) return false;
            range.second = rrange.second;
        }
        else range.second = root->val;
        return true;
    }
};
