#include "../IOLib.hpp"

/**
DFS.
Time: O(n)
Space: O(1)
**/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = (rows > 0)?grid[0].size():0;
        if(!rows || !cols) return 0;
        int count = 0;
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] != '1') continue;
                dfs(grid, row, col);
                count++;
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int row, int col){
        if(grid[row][col] != '1') return;
        grid[row][col] = '2';
        if(row-1 >= 0) dfs(grid, row-1, col);
        if(row+1 < grid.size()) dfs(grid, row+1, col);
        if(col-1 >= 0) dfs(grid, row, col-1);
        if(col+1 < grid[0].size()) dfs(grid, row, col+1);
    }
};
