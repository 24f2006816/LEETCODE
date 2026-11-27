class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> dp(budget + 1, 0);
        int minPrice = INT_MAX;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            minPrice = min(minPrice, price);

            int count = 0;

            for (auto& other : items) {
                if (other[0] % factor == 0) {
                    count++;
                }
            }

            for (int j = budget; j >= price; j--) {
                dp[j] = max(dp[j], dp[j - price] + count);
            }
        }

        int ans = 0;

        for (int i = 0; i <= budget; i++) {
            ans = max(ans, dp[i] + (budget - i) / minPrice);
        }

        return ans;
    }
};