class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> window;
        for (int i = 0; i<n; i++){
            if (i > k){
                window.erase(nums[i-k-1]);
            }
            if (window.count(nums[i])){
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};