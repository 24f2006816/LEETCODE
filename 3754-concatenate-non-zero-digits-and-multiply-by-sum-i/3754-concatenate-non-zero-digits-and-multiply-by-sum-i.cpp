class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        long long sum = 0;

        string s = to_string(n);

        for (char c : s) {
            if (c != '0') {
                int digit = c - '0';
                num = num * 10 + digit;
                sum += digit;
            }
        }

        return num * sum;
    }
};