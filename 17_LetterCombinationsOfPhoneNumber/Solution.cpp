#include "../IOLib.hpp"

/**
This is a solution using DFS.
Time: O(4^n)
Space: O(4^n)
There're iterative version (BFS) and recursive version (DFS).
**/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return result;
        vector<vector<char>> dict{{' '}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        string seed;
        dfs(result, dict, digits, 0, seed);
        return result;
    }
    void dfs(vector<string>& result, vector<vector<char>>& dict, string& digits, int pos, string str){
        if(pos == digits.size()){
            result.push_back(str);
            return;
        }
        int num = digits[pos] - '0';
        for(int i = 0; i < dict[num].size(); i++){
            dfs(result, dict, digits, pos + 1, str + dict[num][i]);
        }
    }
};
