class Solution {
public:
    struct Node{
        Node* child[2];
        Node(){
            child[0] = NULL;
            child[1] = NULL;
        }
    };
    Node* root = new Node();
    void insert(int num){
        Node* curr = root;
        for (int i = 30; i >= 0; i--){
            int bit = (num >> i) & 1;
            if (curr->child[bit] == nullptr){
                curr->child[bit] = new Node();
            }
            curr = curr->child[bit];
        }
    }
    int getMaxXor(int num){
        Node* curr = root;
        int ans = 0;
        for (int i = 30; i >= 0; i--){
            int bit = (num >> i) & 1;
            int opposite = 1-bit;
            if (curr->child[opposite] != nullptr){
                ans |= (1 << i);
                curr = curr->child[opposite];
            }
            else{
                curr = curr->child[bit];
            }
        }
        return ans;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++){
            q.push_back({
                queries[i][0],
                queries[i][1],
                i
            });
        }
        sort(q.begin(), q.end(),[](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        vector<int> ans(queries.size());
        int i = 0;
        for (auto& query : q){
            int x = query[0];
            int m = query[1];
            int index = query[2];
            while (i < nums.size() && nums[i] <= m){
                insert(nums[i]);
                i++;
            }
            if (i == 0){
                ans[index] = -1;
            }
            else{
                ans[index] = getMaxXor(x);
            }
        }
        return ans;
    }
};