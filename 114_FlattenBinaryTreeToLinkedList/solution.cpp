#include "../IOLib.hpp"

/**
Recursive
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
    void flatten(TreeNode* root) {
        helper(root);
    }
    TreeNode* helper(TreeNode* root){
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
        TreeNode* next = root->right;
        TreeNode* tail = helper(root->left);
        if(tail){
            root->right = root->left;
            root->left = NULL;
            tail->right = next;
        }
        return next?helper(next):tail;
    }
};

/**
There're iterative ways
**/
