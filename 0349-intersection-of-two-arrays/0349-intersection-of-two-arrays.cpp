class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end());
        unordered_set<int> ans;

        for (int num: nums2){
            if (st.find(num)!= st.end()){
                ans.insert(num);
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};