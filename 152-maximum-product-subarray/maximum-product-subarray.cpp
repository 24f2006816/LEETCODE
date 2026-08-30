class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int currentMax = nums[0];
        int currentMin = nums[0];

        for (int i= 1; i<n; i++){
            int num = nums[i];
            int tempMax = max({num,num*currentMax, num*currentMin });
            int tempMin = min({num,num*currentMax, num*currentMin });
            currentMax = tempMax;
            currentMin = tempMin;

            maxi = max(maxi, currentMax);
        }
        return maxi;
    }
};