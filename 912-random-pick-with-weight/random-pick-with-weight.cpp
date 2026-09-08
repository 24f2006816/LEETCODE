class Solution {
public:
    vector<int> prefix;
    Solution(vector<int>& w) {
        int sum = 0;
        for (int x : w){
            sum += x;
            prefix.push_back(sum);
        }   
    }
    
    int pickIndex() {
        int target = rand() % prefix.back()+1;
        int l = 0, r = prefix.size()-1;
        while (l < r){
            int mid = l + (r-l)/2;
            if (prefix[mid] >= target)
                r = mid;
            else
                l = mid+1;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */