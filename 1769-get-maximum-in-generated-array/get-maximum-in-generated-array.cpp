class Solution {
public:
    int solve(int n, vector<int>& nums){
        if (n == 0){
            nums[0] = 0;
            return 0;
        }
        if (n == 1){
            nums[1] = 1;
            return 1;
        }
        if (n % 2 == 0){
            int i = n/2;
            nums[n] = solve(i, nums);
            return nums[n];
        }
        int i = n/2;
        nums[n] = solve(i,nums) + solve(i+1, nums);
        return nums[n];
    }
    int getMaximumGenerated(int n) {
        if (n==0) return 0;
        vector<int> nums(n+1);
        int maximum = 0;
        for (int i = 0; i <= n; i++){
            solve(i, nums);
            maximum = max(maximum, nums[i]);
        }
        return maximum;
    }
};