class Solution {
public:
    struct Node{
        Node* child[26];
        int cntPrefix;

        Node(){
            cntPrefix = 0;
            for (int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };
    Node* root;
    Solution(){
        root = new Node();
    }
    void insert(string word){
        Node* curr = root;
        for (char ch : word){
            int idx = ch-'a';
            if (curr->child[idx] == NULL){
                curr->child[idx] = new Node();
            }
            curr = curr->child[idx];
            curr->cntPrefix++;
        }
    }
    int countPrefix(string pref){
        Node* curr = root;
        for (char ch : pref){
            int idx = ch - 'a';
            if (curr->child[idx] == NULL){
                return 0;
            }
            curr = curr->child[idx];
        }
        return curr->cntPrefix;
    }
    int prefixCount(vector<string>& words, string pref) {
        for (string word : words){
            insert(word);
        }
        return  countPrefix(pref);
    }
};