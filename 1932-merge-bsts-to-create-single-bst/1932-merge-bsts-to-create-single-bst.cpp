/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    unordered_map<int, TreeNode*> roots;
    unordered_map<int, int> cnt;
    unordered_set<int> used;

    bool dfs(TreeNode* node, long long low, long long high) {
        if (!node) return true;

        if (node->val <= low || node->val >= high)
            return false;

        // Merge another tree at this leaf
        if (!node->left && !node->right &&
            roots.count(node->val) && !used.count(node->val)) {

            used.insert(node->val);

            TreeNode* t = roots[node->val];
            node->left = t->left;
            node->right = t->right;
        }

        return dfs(node->left, low, node->val) &&
               dfs(node->right, node->val, high);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {

        for (auto t : trees) {
            roots[t->val] = t;
            cnt[t->val]++;
            if (t->left) cnt[t->left->val]++;
            if (t->right) cnt[t->right->val]++;
        }

        TreeNode* root = nullptr;

        // Find the unique overall root
        for (auto t : trees) {
            if (cnt[t->val] == 1) {
                root = t;
                break;
            }
        }

        if (!root) return nullptr;

        used.insert(root->val);

        if (!dfs(root, LLONG_MIN, LLONG_MAX))
            return nullptr;

        if (used.size() != trees.size())
            return nullptr;

        return root;
    }
};