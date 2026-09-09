class Solution {
public:
    string clearDigits(string s) {
        string st;
        for (char c : s){
            if (c >= '0' && c <= '9'){
                st.pop_back();
            }
            else{
                st.push_back(c);
            }
        }
        return st;
    }
};