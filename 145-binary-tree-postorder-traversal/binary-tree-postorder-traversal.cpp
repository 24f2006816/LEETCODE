class Solution {
private:
    void postorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr)
            return;

        postorderHelper(node->left, result);  // Left
        postorderHelper(node->right, result); // Right
        result.push_back(node->val);          // Root
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        postorderHelper(root, result);

        return result;
    }
};