class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }

        bool negative = false;

        if (num < 0) {
            negative = true;
            num = -num;
        }

        string ans;

        while (num > 0) {
            int digit = num % 7;
            ans += char('0' + digit);
            num /= 7;
        }

        // Reverse manually
        int left = 0;
        int right = ans.size() - 1;

        while (left < right) {
            char temp = ans[left];
            ans[left] = ans[right];
            ans[right] = temp;

            left++;
            right--;
        }

        if (negative) {
            ans = "-" + ans;
        }

        return ans;
    }
};