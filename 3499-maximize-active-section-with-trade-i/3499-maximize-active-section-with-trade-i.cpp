class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        int prevZero = INT_MIN;
        int maxGain = 0;
        int n = s.size();

        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }

            int len = j - i;

            if (s[i] == '1') {
                ones += len;
            } else {
                maxGain = max(maxGain, prevZero + len);
                prevZero = len;
            }

            i = j;
        }

        return ones + maxGain;
    }
};