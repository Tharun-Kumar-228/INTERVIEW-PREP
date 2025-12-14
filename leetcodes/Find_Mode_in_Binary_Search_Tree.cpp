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
// class Solution {
// public:
//     int mx = 0;

//     vector<int> findMode(TreeNode* root) {
//         unordered_map<int, int> hm;
//         inorder(root, hm);

//         vector<int> result;
//         for (auto &it : hm) {
//             if (it.second == mx) {
//                 result.push_back(it.first);
//             }
//         }
//         return result;
//     }

//     void inorder(TreeNode* root, unordered_map<int,int> &hm) {
//         if (!root) return;

//         inorder(root->left, hm);

//         hm[root->val]++;
//         mx = max(mx, hm[root->val]);

//         inorder(root->right, hm);
//     }
// };

class Solution {
public:
    int prev = INT_MIN;
    int count = 0;
    int maxCount = 0;
    vector<int> result;

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
    }

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (root->val == prev) {
            count++;
        } else {
            prev = root->val;
            count = 1;
        }

        if (count > maxCount) {
            maxCount = count;
            result.clear();
            result.push_back(root->val);
        } else if (count == maxCount) {
            result.push_back(root->val);
        }

        inorder(root->right);
    }
};
