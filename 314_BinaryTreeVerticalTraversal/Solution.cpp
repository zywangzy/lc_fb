#include "../IOLib.hpp"

/**
Time: O(n)
Space: O(n)
Use a hashtable to keep each node's bias is also ok, but using pair might release
the memory earlier.
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        map<int, vector<int>> dict;
        queue<pair<TreeNode*, int>> line;
        line.push(make_pair(root, 0));
        while(!line.empty()){
            auto p = line.front();
            line.pop();
            dict[p.second].push_back(p.first->val);
            if(p.first->left) line.push(make_pair(p.first->left, p.second-1));
            if(p.first->right) line.push(make_pair(p.first->right, p.second+1));
        }
        for(auto it = dict.begin(); it != dict.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};
