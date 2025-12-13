// // /**
// //  * Definition for a binary tree node.
// //  * struct TreeNode {
// //  *     int val;
// //  *     TreeNode *left;
// //  *     TreeNode *right;
// //  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// //  * };
// //  */
// // class Solution {
// // public:
// //     vector<string> binaryTreePaths(TreeNode* root) {
// //         vector<string> ans;
// //         if (!root) return ans;

// //         if (!root->left && !root->right) {
// //             ans.push_back(to_string(root->val));
// //             return ans;
// //         }

// //         for (string s : binaryTreePaths(root->left)) {
// //             ans.push_back(to_string(root->val) + "->" + s);
// //         }

// //         for (string s : binaryTreePaths(root->right)) {
// //             ans.push_back(to_string(root->val) + "->" + s);
// //         }

// //         return ans;
// //     }
// // };

// class Solution {
// public:
//     void dfs(TreeNode* root, string path, vector<string>& ans) {
//         if (!root) return;

//         if (!path.empty())
//             path += "->";
//         path += to_string(root->val);

//         if (!root->left && !root->right) {
//             ans.push_back(path);
//             return;
//         }

//         dfs(root->left, path, ans);
//         dfs(root->right, path, ans);
//     }

//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> ans;
//         dfs(root, "", ans);
//         return ans;
//     }
// };

class Solution {
public:
    void dfs(TreeNode* node, vector<string>& ans, string& path) {
        if (!node) return;

        int len = path.size();   // save state

        path += to_string(node->val);

        if (!node->left && !node->right) {
            ans.push_back(path);
        } else {
            path += "->";
            dfs(node->left, ans, path);
            dfs(node->right, ans, path);
        }

        path.resize(len);  // backtrack
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;
        dfs(root, ans, path);
        return ans;
    }
};


