#include "../IOLib.hpp"

/**
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
private:
    TreeNode* first; //first and second nodes to be swapped
    TreeNode* second;
    TreeNode* prev; //previous node in in-order traversal
public:
    void recoverTree(TreeNode* root) {
        first = NULL;
        second = NULL;
        traverse(root);
        swap(first->val, second->val);
    }
    void traverse(TreeNode* root){
        if(root->left) traverse(root->left);
        if(prev && root->val <= prev->val){
            if(!first) first = prev;
            second = root;
        }
        prev = root;
        if(root->right) traverse(root->right);
    }
};
