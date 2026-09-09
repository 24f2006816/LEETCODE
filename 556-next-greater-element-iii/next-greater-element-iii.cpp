class Solution {
public:
    int nextGreaterElement(int n) {

        string s = to_string(n);

        int i = s.length() - 2;

        // Step 1: Find pivot
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }

        // No greater permutation exists
        if (i < 0) {
            return -1;
        }

        // Step 2: Find smallest digit greater than s[i]
        int j = s.length() - 1;

        while (s[j] <= s[i]) {
            j--;
        }

        // Step 3: Swap
        swap(s[i], s[j]);

        // Step 4: Reverse suffix
        reverse(s.begin() + i + 1, s.end());

        // Need long long to safely check overflow
        long long ans = stoll(s);

        if (ans > INT_MAX) {
            return -1;
        }

        return (int)ans;
    }
};