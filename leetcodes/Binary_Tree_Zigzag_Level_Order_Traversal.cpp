class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        zigzag(root, 0, res);
        return res;
    }

    void zigzag(TreeNode* root, int level, vector<vector<int>>& res){
        if(root == NULL) return;

        if(res.size() == level){
            res.push_back(vector<int>());  
        }

        if(level % 2 == 0){
            res[level].push_back(root->val); 
        } else {
            res[level].insert(res[level].begin(), root->val); 
        }

        zigzag(root->left, level+1, res);
        zigzag(root->right, level+1, res);
    }
};
