class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> minPrice(n);
        minPrice[0] = prices[0];

        for (int i=1; i <n; i++){
            minPrice[i] = min(minPrice[i-1], prices[i]);
        }
        int maxProfit = 0;
        for (int i = 0; i < n; i++){
            int profit = prices[i] - minPrice[i];
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};