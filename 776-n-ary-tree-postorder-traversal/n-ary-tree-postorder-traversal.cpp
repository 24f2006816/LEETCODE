class Solution {
private:
    void postorderHelper(Node* node, vector<int>& result) {
        if (node == nullptr)
            return;

        // Visit all children first
        for (Node* child : node->children) {
            postorderHelper(child, result);
        }

        // Visit root after all children
        result.push_back(node->val);
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> result;

        postorderHelper(root, result);

        return result;
    }
};