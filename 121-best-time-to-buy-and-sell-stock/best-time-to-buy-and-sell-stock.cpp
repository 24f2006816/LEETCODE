class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < n; i++){
            minPrice = min(minPrice, prices[i]);
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};