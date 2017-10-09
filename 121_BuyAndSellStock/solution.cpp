#include "../IOLib.hpp"

/**
1d DP?
Time: O(n)
Space: O(1)
**/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if(prices.empty()) return profit;
        int minprice = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > minprice)
                profit = max(profit, prices[i] - minprice);
            else
                minprice = prices[i];
        }
        return profit;
    }
};
