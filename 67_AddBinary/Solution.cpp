#include "../IOLib.hpp"

/**
Time complexity: O(max(m, n))
Space complexity: O(max(m, n))
**/

class Solution {
public:
    string addBinary(string a, string b) {
        string res(max(a.size(), b.size()) + 1, '0');
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0, sum = 0;
        int i = 0;
        while(i < min(a.size(), b.size())){
            sum = (a[i] - '0') + (b[i] - '0') + carry;
            res[i] = (sum & 1) + '0';
            carry = sum >> 1;
            i++;
        }
        while(i < a.size()){
            sum = (a[i] - '0') + carry;
            res[i] = (sum & 1) + '0';
            carry = sum >> 1;
            i++;
        }
        while(i < b.size()){
            sum = (b[i] - '0') + carry;
            res[i] = (sum & 1) + '0';
            carry = sum >> 1;
            i++;
        }
        if(carry) res[i] = '1';
        reverse(res.begin(), res.end());
        if(res[0] == '0') res = res.substr(1);
        return res;
    }
};

int main(void){
    string a = readString();
    string b = readString();
    Solution sol;
    cout << "sum = " << sol.addBinary(a, b) << endl;
    return 0;
}
