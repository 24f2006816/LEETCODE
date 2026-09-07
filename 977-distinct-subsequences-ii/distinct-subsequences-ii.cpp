class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(26,0);
        for (char c : s){
            int index = c-'a';
            long long total = accumulate(dp.begin(), dp.end(), 1LL);
            dp[index] = total % MOD;
        }
        return accumulate(dp.begin(), dp.end(), 0LL) % MOD;
    }
};