class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> pos, digit;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> preNum(m + 1, 0);
        vector<int> preSum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            preNum[i + 1] = (preNum[i] * 10 + digit[i]) % MOD;
            preSum[i + 1] = preSum[i] + digit[i];
        }

        // start[i] = first non-zero digit index whose position >= i
        vector<int> start(n + 1, m);
        int p = 0;
        for (int i = 0; i < n; i++) {
            while (p < m && pos[p] < i) p++;
            start[i] = p;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = start[l];
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long num =
                (preNum[R + 1] -
                 preNum[L] * pow10[len] % MOD + MOD) % MOD;

            long long sum = preSum[R + 1] - preSum[L];

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};