#include "../IOLib.hpp"

/**
Time: O(n)
Space: O(height of tree)
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root) return result;
        dfs(result, root, to_string(root->val));
        return result;
    }
    void dfs(vector<string>& result, TreeNode* root, string prev){
        if(!root) return;
        if(!(root->left) && !(root->right)){//leaf
            result.push_back(prev);
            return;
        }
        if(root->left) dfs(result, root->left, prev + "->" + to_string(root->left->val));
        if(root->right) dfs(result, root->right, prev + "->" + to_string(root->right->val));
    }
};
