class Solution {
public:
    void traverse(TreeNode* cur, int depth, vector<vector<int>> &ret){
        if(cur==NULL)
            return;
        else if(ret.size()==depth)
            ret.push_back(vector<int>()); 

        ret[depth].push_back(cur->val);
        traverse(cur->left, depth+1, ret);
        traverse(cur->right, depth+1, ret);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        traverse(root, 0, ret);
        return ret;
    }
};