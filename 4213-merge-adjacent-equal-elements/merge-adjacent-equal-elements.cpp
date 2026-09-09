class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> st;
        for (int x : nums){
            st.push_back(x);
            while (st.size() >= 2 &&
            st[st.size()-1] == st[st.size()-2]){
                long long a = st.back();
                st.pop_back();
                long long b = st.back();
                st.pop_back();
                st.push_back(a+b);
            }
        }
        return st;
    }
};