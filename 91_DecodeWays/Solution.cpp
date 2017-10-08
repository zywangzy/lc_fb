#include "../IOLib.hpp"

/***
Dynamic programming.
Time: O(n)
Space: O(n) (could be O(1))
***/

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        vector<int> counts(s.size(), 0);
        if(s[0] == '0') return 0;
        counts[0] = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '0'){
                if(s[i-1] == '1' || s[i-1] == '2'){
                    counts[i] = (i > 2)?counts[i-2]:1;
                }
                else return 0;
            }
            else if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')){
                counts[i] = counts[i-1] + ((i>2)?counts[i-2]:1);
            }
            else{
                counts[i] = counts[i-1];
            }
        }
        return counts.back();
    }
};
