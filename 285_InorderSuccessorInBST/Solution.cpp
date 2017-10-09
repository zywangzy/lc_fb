#include "../IOLib.hpp"

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root || !p) return NULL;
        if(p->right){
            TreeNode* ptr = p->right;
            while(ptr->left) ptr = ptr->left;
            return ptr;
        }
        stack<TreeNode*> path;
        while(root != p){
            path.push(root);
            if(p->val < root->val){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        while(!path.empty()){
            TreeNode* temp = path.top();
            path.pop();
            if(temp->val > p->val) return temp;
        }
        return NULL;
    }
};
