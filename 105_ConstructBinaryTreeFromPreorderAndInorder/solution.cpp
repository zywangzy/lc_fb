#include "../IOLib.hpp"

/**
Recursive Version. There's also iterative version.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return builder(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* builder(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(ps > pe) return NULL;
        if(ps == pe) return new TreeNode(preorder[ps]);
        int rootval = preorder[ps], pos = is;
        for(int i = is; i <= ie; i++){
            if(inorder[i] == rootval){
                pos = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(preorder[ps]);
        root->left = builder(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
        root->right = builder(preorder, inorder, ps + pos - is + 1, pe, pos + 1, ie);
        return root;
    }
};
