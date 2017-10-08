#include "../IOLib.hpp"

/**
Dynamic programming. Use substring to simplify character manipulations.
Character-wise might be faster but more error-prone.
Time: O(n)
Space: O(1)
**/

class Solution {
public:
    int numDecodings(string s) {
        long f1 = 1, f2 = 1;
        const int num = 1000000007;
        if(s.empty() || s[0] == '0') return 0;
        f2 = count(s.substr(0,1));
        for(int i = 1; i < s.size(); i++){
            long f3 = (f2 * count(s.substr(i,1)) + f1 * count(s.substr(i-1,2)));
            f1 = f2;
            f2 = f3 % num;
        }
        return (int)f2;
    }
    int count(string str){
        if(str.size() == 1){
            if(str[0] == '*') return 9;
            return (str[0] == '0') ? 0 : 1;
        }
        if(str == "**"){
            return 15;
        }
        else if(str[0] == '*'){
            return (str[1] <= '6') ? 2 : 1;
        }
        else if(str[1] == '*'){
            if(str[0] == '1') return 9;
            if(str[0] == '2') return 6;
            return 0;
        }
        else{
            int val = stoi(str);
            return (val >= 10 && val <= 26) ? 1 : 0;
        }
    }
};
