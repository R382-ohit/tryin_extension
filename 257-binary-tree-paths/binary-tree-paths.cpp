/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return root->left == NULL && root->right == NULL;
    }

    void backtrack(TreeNode* root, vector<string>& ans, string& dummy) {
        if (dummy.empty()) {
            dummy += to_string(root->val);
        } else {
            dummy = dummy + "->" + to_string(root->val);
        }

        if (isLeaf(root)) {
            ans.push_back(dummy);
            return;
        }

        string old = dummy;

        if (root->left) {
            backtrack(root->left, ans, dummy);
        }
        dummy = old;
        if (root->right) {
            backtrack(root->right, ans, dummy);
        }
        dummy = old;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        if (isLeaf(root)) {
            return {to_string(root->val)};
        }
        vector<string> ans;
        string dummy = "";
        backtrack(root, ans, dummy);
        return ans;
    }
};