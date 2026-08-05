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
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> in;
        inorder(root, in);
        int n = in.size();
        int minima = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            minima = min(minima, abs(in[i + 1] - in[i]));
        }
        return minima;
    }
};