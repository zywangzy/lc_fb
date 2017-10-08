#include "../IOLib.hpp"

/***
Used BFS to encode binary tree.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        string res;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* ptr = nodes.front();
            nodes.pop();
            if(!ptr) res += "#";
            else{
                res += to_string(ptr->val);
                nodes.push(ptr->left);
                nodes.push(ptr->right);
            }
            if(!nodes.empty()) res += ",";
        }
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        stringstream ss(data);
        vector<string> values;
        string str;
        queue<TreeNode*> nodes;
        while(getline(ss, str, ',')){
            values.push_back(str);
        }
        if(values[0] == "#") return root;
        root = new TreeNode(stoi(values[0]));
        nodes.push(root);
        int i = 1;
        while(!nodes.empty() && i < values.size()){
            TreeNode* ptr = nodes.front();
            nodes.pop();
            if(values[i] != "#"){
                ptr->left = new TreeNode(stoi(values[i]));
                nodes.push(ptr->left);
            }
            i++;
            if(values[i] != "#"){
                ptr->right = new TreeNode(stoi(values[i]));
                nodes.push(ptr->right);
            }
            i++;
        }
        return root;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
