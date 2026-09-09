class Solution {
private:
    int height(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int leftHeight = height(node->left);

        // Left subtree is already unbalanced
        if (leftHeight == -1)
            return -1;

        int rightHeight = height(node->right);

        // Right subtree is already unbalanced
        if (rightHeight == -1)
            return -1;

        // Current node is unbalanced
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};