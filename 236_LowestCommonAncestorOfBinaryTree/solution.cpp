#include "../IOLib.hpp"

/**
This is iterative way. Could also be done by recursive way, using divide and
conquer.
Time: O(n)
Space: O(h)
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> path;
        dfs(root, p, path);
        cout << path.size() << endl;
        if(is_child(path.top(), q)) return p;
        TreeNode* last = path.top();
        path.pop();
        while(!path.empty()){
            if(q == path.top()) return q;
            TreeNode* cur = NULL;
            if(last == path.top()->left)
                cur = path.top()->right;
            else{
                cur = path.top()->left;
            }
            if(is_child(cur, q)) return path.top();
            last = path.top();
            path.pop();
        }
        return root;
    }
    bool dfs(TreeNode* root, TreeNode* p, stack<TreeNode*>& path){
        path.push(root);
        if(root == p)
            return true;
        if(root->left)
            if(dfs(root->left, p, path)) return true;
        if(root->right)
            if(dfs(root->right, p, path)) return true;
        path.pop();
        return false;
    }
    bool is_child(TreeNode* parent, TreeNode* child){
        if(!parent) return false;
        if(parent == child) return true;
        if(parent->left && is_child(parent->left, child)) return true;
        if(parent->right && is_child(parent->right, child)) return true;
        return false;
    }
};
