class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);
        for (int x : nums1){
            if (binary_search(nums2.begin(), nums2.end(), x))
                return x;
        }
        return -1;
    }
};