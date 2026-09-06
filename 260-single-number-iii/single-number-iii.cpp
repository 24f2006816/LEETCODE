class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums)
            mp[x]++;
        vector<int> ans;
        for (auto p : mp)
            if (p.second == 1)
                ans.push_back(p.first);
        return ans;
    }
};