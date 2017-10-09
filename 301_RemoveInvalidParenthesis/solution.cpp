#include "../IOLib.hpp"

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> dict;
        queue<string> q;
        q.push(s);
        dict.insert(s);
        bool stop = false;
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                string cur = q.front();
                q.pop();
                if(valid(cur)){
                    res.push_back(cur);
                    stop = true;
                }
                if(!stop){
                    for(int j = 0; j < cur.size(); j++){
                        if(cur[j] != '(' && cur[j] != ')') continue;
                        if(j > 0 && cur[j] == cur[j-1]) continue;
                        string next = cur.substr(0,j) + cur.substr(j+1);
                        if(dict.find(next) != dict.end()) continue;
                        q.push(next);
                        dict.insert(q.back());
                    }
                }
            }
            if(stop) break;
        }
        return res;
    }
    bool valid(string s){
        int count = 0;
        for(auto c: s){
            if(c == '(') count++;
            if(c == ')') count--;
            if(count < 0) return false;
        }
        return count == 0;
    }
};
