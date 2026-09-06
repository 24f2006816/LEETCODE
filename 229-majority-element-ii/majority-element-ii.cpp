class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int x : nums)
            mp[x]++;
        for (auto x : mp){
            if (x.second > nums.size()/3)
                ans.push_back(x.first);
        }
        return ans;
    }
};