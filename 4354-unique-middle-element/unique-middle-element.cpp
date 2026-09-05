class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }
        if (mpp[nums[nums.size()/2]] !=1 ) return false;
        else return true;
    }
};