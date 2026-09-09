class Solution {
private:
    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr)
            return;

        inorderHelper(node->left, result);  // Left
        result.push_back(node->val);        // Root
        inorderHelper(node->right, result); // Right
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        inorderHelper(root, result);

        return result;
    }
};