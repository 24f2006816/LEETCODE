class Solution {
private:
    TreeNode* prev = nullptr;
    int minimum = INT_MAX;

    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;

        inorder(root->left);

        if (prev != nullptr) {
            minimum = min(minimum, root->val - prev->val);
        }

        prev = root;

        inorder(root->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return minimum;
    }
};