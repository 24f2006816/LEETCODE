class Solution {
private:
    void preorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr)
            return;

        result.push_back(node->val);        // Root
        preorderHelper(node->left, result); // Left
        preorderHelper(node->right, result);// Right
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        preorderHelper(root, result);

        return result;
    }
};