class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> curr(k, 0);

        for (int x : nums) {
            vector<long long> next(k, 0);

            // Start a new subarray with x
            next[x % k]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (curr[r] > 0) {
                    int newRemainder = (r * (x % k)) % k;
                    next[newRemainder] += curr[r];
                }
            }

            curr = next;

            // Add subarrays ending at current element
            for (int r = 0; r < k; r++) {
                ans[r] += curr[r];
            }
        }

        return ans;
    }
};