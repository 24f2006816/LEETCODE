class Solution {
public:

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int& postIndex, int inStart, int inEnd) {

        if (inStart > inEnd)
            return NULL;

        // Last element of postorder is the root
        int rootValue = postorder[postIndex];
        postIndex--;

        TreeNode* root = new TreeNode(rootValue);

        // Find root in inorder
        int index = inStart;

        while (inorder[index] != rootValue) {
            index++;
        }

        // IMPORTANT:
        // Build right first
        root->right = build(inorder, postorder,
                            postIndex, index + 1, inEnd);

        // Then build left
        root->left = build(inorder, postorder,
                           postIndex, inStart, index - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int postIndex = postorder.size() - 1;

        return build(inorder, postorder,
                     postIndex, 0, inorder.size() - 1);
    }
};