#include "../IOLib.hpp"

/**
Time complexity: O(n^n * n^2) = O(n^(n+2))? Not sure...
Space complexity: O(n)
**/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> pos;
        solver(result, pos, n);
        return result;
    }
    void solver(vector<vector<string>>& result, vector<int>& pos, int n){
        for(int i = 0; i < pos.size(); i++){
            for(int j = i+1; j < pos.size(); j++){
                if(pos[i] == pos[j] || abs(pos[i] - pos[j]) == abs(i - j))
                    return;
            }
        }
        if(pos.size() == n){
            save(result, pos, n);
            return;
        }
        for(int i = 0; i < n; i++){
            pos.push_back(i);
            solver(result, pos, n);
            pos.pop_back();
        }
    }
    void save(vector<vector<string>>& result, vector<int>& pos, int n){
        vector<string> board(n, string(n, '.'));
        for(int i = 0; i < n; i++){
            board[i][pos[i]] = 'Q';
        }
        result.push_back(board);
    }
};
