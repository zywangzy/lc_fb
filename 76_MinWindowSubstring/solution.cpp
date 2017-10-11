#include "../IOLib.hpp"

class Solution {
public:
    string minWindow(string s, string t) {
        int counter = 0;
        unordered_map<char, int> map;
        unordered_map<char, int> window;
        for(int i = 0; i < t.size(); i++){
            map[t[i]]++;
        }
        int minlen = INT_MAX;
        string res;
        for(int i = 0, j = 0; i < s.length(); i++){
            char c = s[i];
            if(map.find(c) != map.end()){
                window[c]++;
                if(window[c] <= map[c])
                    counter++;
            }
            if(counter >= t.length()){
                while(map.find(s[j]) == map.end() || window[s[j]] > map[s[j]]){
                    window[s[j]]--;
                    j++;
                }
                if(i - j + 1 < minlen){
                    minlen = i - j + 1;
                    res = s.substr(j, minlen);
                }
            }
        }
        return res;
    }
};

int main(void){
    string s = readString();
    string t = readString();
    Solution sol;
    cout << sol.minWindow(s, t) << endl;
    return 0;
}
