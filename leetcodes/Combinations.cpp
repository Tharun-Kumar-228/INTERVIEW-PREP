class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int>combi;
        backtrack(n,k,res,combi,1);
        return res;
    }

    void backtrack(int n,int k,   vector<vector<int>> &res,   vector<int>&combi,   int curr){
        if(combi.size() == k){
            res.push_back(combi);
            return;
        }
        for(int i=curr;i<=n;i++){
            combi.push_back(i);
            backtrack(n,k,res,combi,i+1);
            combi.pop_back();
        }
    }
};
