
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1000000007;
        int m = grid.size();
        int n = grid[0].size();

        // dp[j][0]: ways from the cell above, moving down
        // dp[j][1]: ways from the cell to the left, moving right
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[0][0] = 1;
        dp[0][1] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int fromAbove = dp[j][0];
                int fromLeft = (j == 0) ? 0 : dp[j - 1][1];

                if (grid[i][j] == 0) {
                    dp[j][0] = (fromAbove + fromLeft) % MOD;
                    dp[j][1] = dp[j][0];
                } else {
                    dp[j][0] = fromLeft;
                    dp[j][1] = fromAbove;
                }
            }
        }

        return dp[n - 1][0];
    }
};
