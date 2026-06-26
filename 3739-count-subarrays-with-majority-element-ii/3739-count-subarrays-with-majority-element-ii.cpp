class Fenwick {
public:
    int n;
    vector<int> bit;

    Fenwick(int sz) {
        n = sz;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick bit(vals.size() + 2);

        auto getIndex = [&](int x) {
            return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
        };

        long long ans = 0;

        bit.update(getIndex(pref[0]), 1);

        for (int i = 1; i <= n; i++) {
            int idx = lower_bound(vals.begin(), vals.end(), pref[i]) - vals.begin();
            ans += bit.query(idx);
            bit.update(getIndex(pref[i]), 1);
        }

        return ans;
    }
};