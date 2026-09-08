class Solution {
public:
    long long minimumSteps(string s) {
        long long ones = 0;
        long long ans = 0;
        for (char ch: s){
            if (ch == '1'){
                ones++;
            }else{
                ans += ones;
            }
        }
        return ans;
    }
};