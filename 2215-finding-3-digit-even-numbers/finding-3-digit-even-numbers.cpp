class Solution {
public:

    vector<int> ans;
    int freq[10] = {};

    void solve(int pos, int num) {

        // We have selected 3 digits
        if (pos == 3) {
            ans.push_back(num);
            return;
        }

        for (int digit = 0; digit <= 9; digit++) {

            // Digit not available
            if (freq[digit] == 0)
                continue;

            // First digit cannot be 0
            if (pos == 0 && digit == 0)
                continue;

            // Last digit must be even
            if (pos == 2 && digit % 2 != 0)
                continue;

            // Choose
            freq[digit]--;

            solve(pos + 1, num * 10 + digit);

            // Backtrack
            freq[digit]++;
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {

        for (int digit : digits) {
            freq[digit]++;
        }

        solve(0, 0);

        return ans;
    }
};