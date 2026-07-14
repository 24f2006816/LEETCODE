class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int dp[201][201][201];
    int n;

    int solve(int idx, int g1, int g2, vector<int>& nums) {
        if (idx == n)
            return (g1 > 0 && g1 == g2);

        int &ans = dp[idx][g1][g2];
        if (ans != -1) return ans;

        long long res = 0;

        // Skip current element
        res += solve(idx + 1, g1, g2, nums);

        // Put in first subsequence
        res += solve(idx + 1, std::gcd(g1, nums[idx]), g2, nums);

        // Put in second subsequence
        res += solve(idx + 1, g1, std::gcd(g2, nums[idx]), nums);

        return ans = res % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};