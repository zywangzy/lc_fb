#include "../IOLib.hpp"

/**
Straightforward solution: O(mnp)
Optimized solution (this one): O(mnp) but utilized sparse attribute.
Another solution might use two maps to store non-zero element positions and values.
**/
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result(A.size(), vector<int>(B[0].size(), 0));
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[i].size(); j++){
                if(A[i][j]){
                    for(int k = 0; k < B[0].size(); k++){
                        result[i][k] += A[i][j] * B[j][k];
                    }
                }
            }
        }
        return result;
    }
};


