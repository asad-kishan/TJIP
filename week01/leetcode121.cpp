// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int i = 0;
        int j = 1;

        while(j < prices.size()) {
            int profit = prices[j] - prices[i];
            if(profit < 0) {
                i = j;
            } 
            else if(profit > max_profit) {
                max_profit = profit;
            }
            j++;
        }

        return max_profit;
    }
};
