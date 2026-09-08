class Solution {
public:

    int firstOccurrence(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                ans = mid;
                r = mid - 1;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return ans;
    }

    int lastOccurrence(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                ans = mid;
                l = mid + 1;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return ans;
    }

    vector<int> targetIndices(vector<int>& nums, int target) {

        // Manual sorting
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }

        int first = firstOccurrence(nums, target);
        int last = lastOccurrence(nums, target);

        vector<int> ans;

        if (first == -1)
            return ans;

        for (int i = first; i <= last; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};