#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (exp) {
            if (exp & 1) res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        int S = 2 * m;

        auto UP = [&](int v) {
            return v;
        };

        auto DOWN = [&](int v) {
            return m + v;
        };

        Matrix T(S, vector<long long>(S, 0));

        for (int v = 0; v < m; v++) {

            // down[x] -> up[v] when x < v
            for (int x = 0; x < v; x++) {
                T[UP(v)][DOWN(x)] = 1;
            }

            // up[x] -> down[v] when x > v
            for (int x = v + 1; x < m; x++) {
                T[DOWN(v)][UP(x)] = 1;
            }
        }

        vector<long long> base(S, 0);

        // Length = 2 states
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < m; b++) {

                if (a == b) continue;

                if (a < b)
                    base[UP(b)]++;

                else
                    base[DOWN(b)]++;
            }
        }

        Matrix P = power(T, n - 2);

        vector<long long> ansState(S, 0);

        for (int i = 0; i < S; i++) {
            for (int j = 0; j < S; j++) {
                ansState[i] =
                    (ansState[i] + P[i][j] * base[j]) % MOD;
            }
        }

        long long ans = 0;

        for (long long x : ansState) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};