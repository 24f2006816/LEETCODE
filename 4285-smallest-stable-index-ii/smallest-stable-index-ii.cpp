class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // Right pointer preprocessing
        vector<int> right(n);
        right[n - 1] = nums[n - 1];

        int j = n - 2;

        while (j >= 0) {
            right[j] = min(nums[j], right[j + 1]);
            j--;
        }

        // Two-pointer style scan
        int i = 0;
        int maxLeft = INT_MIN;

        while (i < n) {
            maxLeft = max(maxLeft, nums[i]);

            if (maxLeft - right[i] <= k) {
                return i;
            }

            i++;
        }

        return -1;
    }
};