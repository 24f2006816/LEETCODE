class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int x : nums) cnt[x]++;

        // Any single element can form a subset of length 1
        int ans = 1; 

        // Handle 1 separately
        if (cnt.count(1)) {
            ans = (cnt[1] % 2 ? cnt[1] : cnt[1] - 1);
        }

        for (auto &[x, f] : cnt) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            // Advance as long as the current number can form the left/right pairs
            while (cnt.count(cur) && cnt[cur] >= 2) {
                len += 2;

                // Prevent overflow before squaring
                if (cur > 1000000000LL / cur) {
                    cur = 1000000001LL; // Move to a value that doesn't exist in map
                    break;
                }

                cur = cur * cur;
            }

            // The loop breaks when 'cur' can no longer be paired. 
            // If we have at least 1 copy left of this 'cur', it perfectly forms the peak!
            if (cnt.count(cur) && cnt[cur] >= 1) {
                len += 1;
            } else {
                // If 'cur' doesn't exist at all, the previous number in the chain 
                // must be turned into the peak instead of a pair.
                len -= 1;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};