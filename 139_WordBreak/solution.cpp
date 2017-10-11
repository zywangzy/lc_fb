#include "../IOLib.hpp"

/**
DP.
Time: O(n^2)
Space: O(n)
**/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return true;
        if(wordDict.empty()) return false;
        unordered_set<string> dict;
        int maxlen = 0, minlen = INT_MAX;
        for(auto str: wordDict){
            dict.insert(str);
            maxlen = max((int)str.size(), maxlen);
            minlen = min((int)str.size(), minlen);
        }
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++){
            for(int len = minlen; len <= min(maxlen, i); len++){
                if(dict.find(s.substr(i-len, len)) != dict.end() && dp[i-len]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
