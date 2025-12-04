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
private:
    vector<TreeNode*> q;  // custom queue
    int idx = 0;          // global index for dequeue()

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;

        enqueue(root);

        while (idx < q.size()) {   // queue not empty
            int size = q.size() - idx;  
            vector<int> level;

            while (size--) {
                TreeNode* node = dequeue(); 
                level.push_back(node->val);

                if (node->left) enqueue(node->left);
                if (node->right) enqueue(node->right);
            }
            res.push_back(level);
        }
        return res;
    }

    void enqueue(TreeNode* node) {
        q.push_back(node);
    }

    TreeNode* dequeue() {
        return q[idx++];  
    }
};
