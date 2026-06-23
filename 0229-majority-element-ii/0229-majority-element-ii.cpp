class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        vector<int> result;

        unordered_map<int, int> mpp;

        int mini = (n/3) + 1;

        for (int i = 0; i <n; i++){
            mpp[nums[i]]++;

            if (mpp[nums[i]] == mini){
                result.push_back(nums[i]);
            }
            if (result.size() == 2){
                break;
            }
        }
        return result;
    }
};