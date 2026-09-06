class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int num = left; num <= right; num++){
            int n = num;
            bool good = true;
            while (n){
                int digit = n % 10;
                if (digit == 0 || num % digit != 0){
                    good = false;
                    break;
                }
                n /= 10;
            }
            if (good)
                ans.push_back(num);
        }
        return ans;
    }
};