#include "../IOLib.hpp"

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        vector<int> max(str.size(), str.size()-1);
        for(int i = str.size() - 2; i >= 0; i--){
            if(str[i] > str[max[i+1]]){
                max[i] = i;
            }
            else max[i] = max[i+1];
        }
        for(int i = 0; i < str.size(); i++){
            if(i != max[i] && str[i] != str[max[i]]){
                swap(str[i], str[max[i]]);
                break;
            }
        }
        return stoi(str);
    }
};
