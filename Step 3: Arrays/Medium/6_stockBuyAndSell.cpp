// Following is the solution for: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

// Optimal
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minPrice = prices[0];
        int profit;
        for (int i = 1; i < prices.size(); i++) {
            profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};