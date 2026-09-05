class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size();
        if ( n <= 2) return -1;
        sort(nums.begin(), nums.end());
        int min_el = nums[0];
        int max_el = nums[n-1];
        for (auto x : nums){
            if (x != max_el && x != min_el)
                return x;
        }
        return -1;
    }
};