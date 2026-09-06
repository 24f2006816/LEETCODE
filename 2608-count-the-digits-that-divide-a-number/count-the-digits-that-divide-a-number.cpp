class Solution {
public:
    int countDigits(int num) {
        int n = num, ans = 0;
        while (n){
            int digit = n%10;
            if (digit != 0 && num % digit == 0)
                ans++;
            n /= 10;
        }
        return ans;
    }
};