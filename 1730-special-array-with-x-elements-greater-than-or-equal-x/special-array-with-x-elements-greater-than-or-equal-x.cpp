class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n;
        while (l <= r){
            int x = l + (r-l)/2;
            int count = 0;
            for (int num : nums){
                if (num >= x)
                count++;
            }
            if (count == x)
                return x;
            if (count > x)
                l = x+1;
            else
                r = x-1;
        }
        return -1;
    }
};