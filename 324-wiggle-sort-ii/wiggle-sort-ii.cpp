class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> a = nums;
        sort(a.begin(), a.end());

        int n = nums.size();
        int mid = (n + 1) / 2;
        int j = mid - 1;
        int k = n - 1;

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0)
                nums[i] = a[j--];
            else
                nums[i] = a[k--];
        }
    }
};