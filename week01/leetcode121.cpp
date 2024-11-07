// 121. Best Time to Buy and Sell Stock >> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Time: O(N) where N is the size of the array
// Space: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, l = 0, r = 1;
        while(r < prices.size()) {
            int profit = prices[r] - prices[l];
            if(profit < 0) {
                l = r;
            } 
            else if(profit > max_profit) {
                max_profit = profit;
            }
            r++;
        }
        return max_profit;
    }
};
