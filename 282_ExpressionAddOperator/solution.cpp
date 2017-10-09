#include "../IOLib.hpp"

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        for(int i = 1; i <= num.size(); i++){
            string cur = num.substr(0, i);
            long curval = stol(cur);
            if(to_string(curval).size() != cur.size()) continue;
            dfs(res, num, cur, i, curval, curval, target, '#');
        }
        return res;
    }
    void dfs(vector<string>& res, const string num, string pre, int pos, long preval, long diff, int target, char op){
        if(pos == num.size() && preval == target){
            res.push_back(pre);
            return;
        }
        for(int i = 1; i <= num.size() - pos; i++){
            string cur = num.substr(pos, i);
            if(cur.size() > 1 && cur[0] == '0') break;
            long curval = stol(cur);
            if(to_string(curval).size() != cur.size()) continue;
            dfs(res, num, pre+"+"+cur, pos+i, preval + curval, curval, target, '+');
            dfs(res, num, pre+"-"+cur, pos+i, preval - curval, -curval, target, '-');
            dfs(res, num, pre+"*"+cur, pos+i, preval-diff+diff*curval/*weird here, don't need to check +/- ???*/, diff*curval, target, '-');
        }
    }
};

int main(void){
    string str = readString();
    int target = readInt();
    Solution sol;
    vector<string> res = sol.addOperators(str, target);
    cout << "[ ";
    for(auto s: res){
        cout << "\"" << s << "\", " << endl; 
    }
    cout << " ]" << endl;
    return 0;
}
