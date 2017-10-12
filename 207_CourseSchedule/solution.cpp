#include "../IOLib.hpp"

/**
BFS. Calculate in-degree for each node.
Time: O(n^2 + m)
Space: O(m + n)
**/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> neighbors(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto p: prerequisites){
            neighbors[p.second].push_back(p.first);
            indegree[p.first]++;
        }
        for(int i = 0; i < numCourses; i++){
            int j = 0;
            for(; j < numCourses; j++){
                if(indegree[j] == 0) break;
            }
            if(j == numCourses) return false;
            indegree[j] = -1;
            for(auto n: neighbors[j]){
                indegree[n]--;
            }
        }
        return true;
    }
};
