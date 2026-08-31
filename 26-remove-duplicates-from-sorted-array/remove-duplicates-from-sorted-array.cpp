class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // C++ STL solution
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};