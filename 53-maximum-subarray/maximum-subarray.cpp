class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int current = nums[0];
        int maximum = nums[0];

        for (int i = 1; i < n; i++) {
            current = max(nums[i], current + nums[i]);
            maximum = max(maximum, current);
        }

        return maximum;
    }
};