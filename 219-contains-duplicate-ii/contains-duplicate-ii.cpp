class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> lastIndex;
        for (int i = 0; i<n; i++){
            if (lastIndex.find(nums[i]) != lastIndex.end()){
            int prevIndex = lastIndex[nums[i]];

            if(i-prevIndex <= k){
                return true;
            }
            }
            lastIndex[nums[i]] = i;
        }
        return false;
    }
};