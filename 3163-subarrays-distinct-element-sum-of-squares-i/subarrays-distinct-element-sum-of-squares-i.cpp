
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> seen;

            for (int j = i; j < n; j++) {
                bool found = false;

                for (int k = 0; k < seen.size(); k++) {
                    if (seen[k] == nums[j]) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    seen.push_back(nums[j]);
                }

                int distinct = seen.size();
                ans += distinct * distinct;
            }
        }

        return ans;
    }
};
