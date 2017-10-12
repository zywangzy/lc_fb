#include "../IOLib.hpp"

/**
DP.
Time: O(mn)
Space: O(mn)
**/

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s == p) return true;
        if(p == "*") return true;
        //recursive or dp
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= p.size(); i++){
            dp[0][i] = dp[0][i-1] && (p[i-1] == '*'); // by default
        }
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= p.size(); j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j-1] || dp[i-1][j];
                }
                else{
                    bool first_match = (s[i-1] == p[j-1]) || (p[j-1] == '?');
                    dp[i][j] = first_match && dp[i-1][j-1];
                }
            }
        }
        return dp.back().back();
    }
};
