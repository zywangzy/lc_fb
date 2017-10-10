#include "../IOLib.hpp"

/***
Iterative.
Time: O(n^2)???
Space: O(n)
***/

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i = 2; i <= n; i++){
            string prev = res;
            res = "";
            int count = 1, j = 0;
            while(j < prev.size()){
                while(j < prev.size() - 1 && prev[j+1] == prev[j]){
                    count++; j++;
                }
                res += to_string(count) + prev[j];
                count = 1;
                j++;
            }
        }
        return res;
    }
};
