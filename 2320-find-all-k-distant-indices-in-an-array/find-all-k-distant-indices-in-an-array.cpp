class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++){
            if (nums[i] == key){
                int left = max(0, i-k);
                int right = min(n-1, i+k);
                for (int j = left; j <= right; j++){
                    ans.push_back(j);
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};