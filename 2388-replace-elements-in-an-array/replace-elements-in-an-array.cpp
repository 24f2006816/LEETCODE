class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i;
        }   
        for (auto &op : operations){
            int oldValue = op[0];
            int newValue = op[1];
            int index = mp[oldValue];
            nums[index] = newValue;
            mp[newValue] = index;
        }
        return nums;
    }
};