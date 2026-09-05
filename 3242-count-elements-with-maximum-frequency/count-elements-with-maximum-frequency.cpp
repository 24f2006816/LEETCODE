class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n  = nums.size();
        for (int x : nums){
            mpp[x]++;
        }
        int maxi = 0;
        int ans = 0;
        for (auto &it : mpp){
            maxi = max(maxi, it.second);
        }
        for (auto &it: mpp){
            if(it.second == maxi){
                ans += it.second;
            }
        }
        return ans;
    }
};