#include "../IOLib.hpp"

/***
BST: constantly find the most left one. Then its right child's most left child.
Time:
Constructor: O(h)
hasNext: O(1)
next: O(h)
Space: O(h)
***/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(root){
            path.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !path.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* ptr = path.top();
        path.pop();
        TreeNode* temp = ptr->right;
        while(temp){
            path.push(temp);
            temp = temp->left;
        }
        return ptr->val;
    }
    stack<TreeNode*> path;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
