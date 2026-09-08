class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;

        for (int x : nums) {
            int l = 0, r = v.size();

            // First position where v[pos] >= x
            while (l < r) {
                int mid = l + (r - l) / 2;

                if (v[mid] >= x)
                    r = mid;
                else
                    l = mid + 1;
            }

            if (l == v.size())
                v.push_back(x);
            else
                v[l] = x;
        }

        return v.size();
    }
};