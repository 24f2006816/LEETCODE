class Solution {
public:

    struct Node {
        Node* child[26][26];
        int count;

        Node() {
            count = 0;

            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    child[i][j] = NULL;
                }
            }
        }
    };

    Node* root;

    long long countPrefixSuffixPairs(vector<string>& words) {

        root = new Node();

        long long ans = 0;

        for(string word : words) {

            Node* curr = root;

            int n = word.size();

            for(int i = 0; i < n; i++) {

                int prefixChar = word[i] - 'a';
                int suffixChar = word[n - 1 - i] - 'a';

                if(curr->child[prefixChar][suffixChar] == NULL) {

                    curr->child[prefixChar][suffixChar] = new Node();
                }

                curr = curr->child[prefixChar][suffixChar];

                // Number of previous words having
                // exactly this prefix + suffix
                ans += curr->count;
            }

            curr->count++;
        }

        return ans;
    }
};