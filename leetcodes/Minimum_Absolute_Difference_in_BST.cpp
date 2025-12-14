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
    int minV = INT_MAX;
    int prev = -1;

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minV;
    }

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev != -1) {
            minV = min(minV, root->val - prev);
        }
        prev = root->val;

        inorder(root->right);
    }
};
