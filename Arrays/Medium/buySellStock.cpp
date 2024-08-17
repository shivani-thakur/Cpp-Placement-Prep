// Following is the solution for: https://leetcode.com/problems/best-time-to-buy-and-sell-stock

// Brute force
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxSum = 0;
        int n = prices.size();
        for(int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (prices[j] > prices[i])
                    maxSum = max(maxSum, prices[j] - prices[i]);
            }
        }
        return maxSum;
    }
};

// Optimal using DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minEle = prices[0];
        int maxProf = 0;
        for (auto it: prices) {
            int cost = it - minEle;
            maxProf = max(maxProf, cost);
            minEle = min(minEle, it);
        }
        return maxProf;
    }
};