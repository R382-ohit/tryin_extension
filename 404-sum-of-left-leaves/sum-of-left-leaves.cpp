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
        if (root == NULL)
            return false;
        return root->left == NULL && root->right == NULL;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int sum = 0;
        if (isLeaf(root)) {
            return 0;
        }
        if (root->left != NULL && isLeaf(root->left)) {
            sum += root->left->val;
        }
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};