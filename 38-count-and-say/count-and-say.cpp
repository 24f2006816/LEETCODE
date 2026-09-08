class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 2; i <= n; i++){
            string next="";
            int j = 0;
            while (j < ans.size()){
                char current = ans[j];
                int count = 0;
                while (j < ans.size() && ans[j] == current){
                    count++;
                    j++;
                }
                next += to_string(count);
                next += current;
            }
            ans = next;
        }
        return ans;
    }
};