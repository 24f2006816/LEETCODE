class Solution {
private:
    void preorderHelper(Node* node, vector<int>& result) {
        if (node == nullptr)
            return;

        // Visit root first
        result.push_back(node->val);

        // Then visit all children
        for (Node* child : node->children) {
            preorderHelper(child, result);
        }
    }

public:
    vector<int> preorder(Node* root) {
        vector<int> result;

        preorderHelper(root, result);

        return result;
    }
};