#include "../IOLib.hpp"

/**
Iterative version. Could also be done in recursively.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(postorder.back());
        TreeNode* node = root;
        stack<TreeNode*> st;
        st.push(root);
        int size = inorder.size();
        int i = size - 2, j = size - 1;
        int flag = 0;
        while(i >= 0){
            if(!st.empty() && st.top()->val == inorder[j]){
                node = st.top();
                st.pop();
                flag = 1;
                j--;
            }
            else{
                if(flag == 0){
                    node->right = new TreeNode(postorder[i]);
                    node = node->right;
                    st.push(node);
                    i--;
                }
                else{
                    node->left = new TreeNode(postorder[i]);
                    node = node->left;
                    st.push(node);
                    i--;
                    flag = 0;
                }
            }
        }
        return root;
    }
};
