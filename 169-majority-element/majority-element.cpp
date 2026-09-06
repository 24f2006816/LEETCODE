class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for (auto x: nums){
            if (mp[x] > nums.size()/2){
                return x;
            }
        }
        return -1;
    }
};