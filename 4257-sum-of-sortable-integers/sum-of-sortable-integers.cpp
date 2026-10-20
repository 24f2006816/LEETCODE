
class Solution {
public:
    bool check(vector<int>& nums, vector<int>& sortedNums, int start, int k) {
        vector<int> lps(k, 0);

        int len = 0;
        int i = 1;

        while (i < k) {
            if (sortedNums[start + i] == sortedNums[start + len]) {
                lps[i] = ++len;
                i++;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }

        int j = 0;
        int pos = 0;
        int limit = 2 * k - 1;

        while (pos < limit) {
            int current = nums[start + pos % k];

            if (current == sortedNums[start + j]) {
                pos++;
                j++;

                if (j == k)
                    return true;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                pos++;
            }
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(100001, 0);

        for (int x : nums)
            freq[x]++;

        vector<int> sortedNums;
        sortedNums.reserve(n);

        for (int x = 1; x <= 100000; x++) {
            while (freq[x] > 0) {
                sortedNums.push_back(x);
                freq[x]--;
            }
        }

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool valid = true;

            for (int start = 0; start < n; start += k) {
                if (!check(nums, sortedNums, start, k)) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ans += k;
        }

        return ans;
    }
};
