class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](string a, string b){
            if (a.length() != b.length())
                return a.length() > b.length();
            return a > b;
        });
        return nums[k-1];
    }
};