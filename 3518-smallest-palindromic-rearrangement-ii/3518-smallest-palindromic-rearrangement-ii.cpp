class Solution {
public:
    const long long LIM = 1000001; // k <= 1e6

    string smallestPalindrome(string s, int k) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        vector<int> half(26, 0);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) mid.push_back(char('a' + i));
            half[i] = cnt[i] / 2;
        }

        if (countWays(half) < k) return "";

        string left;
        int len = 0;
        for (int x : half) len += x;

        while ((int)left.size() < len) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;
                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }

private:
    long long nCk(int n, int k) {
        if (k > n) return 0;
        k = min(k, n - k);

        long long ans = 1;
        for (int i = 1; i <= k; i++) {
            ans = ans * (n - i + 1) / i;
            if (ans >= LIM) return LIM;
        }
        return ans;
    }

    long long countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        long long ans = 1;
        int rem = total;

        for (int x : cnt) {
            ans *= nCk(rem, x);
            if (ans >= LIM) return LIM;
            rem -= x;
        }
        return ans;
    }
};