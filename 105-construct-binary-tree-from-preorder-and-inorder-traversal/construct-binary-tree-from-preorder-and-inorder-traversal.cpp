/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd){
        if (inStart > inEnd) return nullptr;
        int rootValue = preorder[preIndex];
        preIndex++;
        TreeNode* root = new TreeNode(rootValue);
        int index = inStart;
        while (inorder[index] != rootValue){
            index++;
        }
        root->left = build(preorder, inorder, preIndex, inStart, index-1);
        root->right = build(preorder, inorder, preIndex, index+1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        return build(preorder, inorder, preIndex, 0, inorder.size() -1);
    }
};