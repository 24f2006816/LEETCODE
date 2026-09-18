class Solution {
public:

    struct Node {
        Node* child[2];

        Node() {
            child[0] = NULL;
            child[1] = NULL;
        }
    };

    Node* root = new Node();

    void insert(int num) {
        Node* curr = root;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (curr->child[bit] == NULL) {
                curr->child[bit] = new Node();
            }

            curr = curr->child[bit];
        }
    }

    int findMaxXor(int num) {
        Node* curr = root;
        int ans = 0;

        for (int i = 30; i >= 0; i--) {

            int bit = (num >> i) & 1;

            // Opposite bit
            int want = 1 - bit;

            if (curr->child[want] != NULL) {
                ans |= (1 << i);
                curr = curr->child[want];
            }
            else {
                curr = curr->child[bit];
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {

        // Put every number into Trie
        for (int num : nums) {
            insert(num);
        }

        int maxi = 0;

        // Find best partner for every number
        for (int num : nums) {
            maxi = max(maxi, findMaxXor(num));
        }

        return maxi;
    }
};