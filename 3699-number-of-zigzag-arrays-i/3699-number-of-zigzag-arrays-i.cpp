class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m), down(m);

        // length = 2
        for (int x = 0; x < m; x++) {
            up[x] = x;
            down[x] = m - x - 1;
        }

        vector<int> pref(m), suff(m);
        vector<int> newUp(m), newDown(m);

        for (int len = 3; len <= n; len++) {

            pref[0] = down[0];
            for (int i = 1; i < m; i++) {
                pref[i] = pref[i - 1] + down[i];
                if (pref[i] >= MOD) pref[i] -= MOD;
            }

            suff[m - 1] = up[m - 1];
            for (int i = m - 2; i >= 0; i--) {
                suff[i] = suff[i + 1] + up[i];
                if (suff[i] >= MOD) suff[i] -= MOD;
            }

            fill(newUp.begin(), newUp.end(), 0);
            fill(newDown.begin(), newDown.end(), 0);

            for (int x = 0; x < m; x++) {

                if (x > 0)
                    newUp[x] = pref[x - 1];

                if (x + 1 < m)
                    newDown[x] = suff[x + 1];
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};