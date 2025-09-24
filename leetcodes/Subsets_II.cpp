class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> combi;
        subsets(res,combi,nums,0);
        return res;
    }

    void subsets( vector<vector<int>> &res,vector<int> &combi,vector<int>& nums,int start ){
        res.push_back(combi);
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1]) continue;
            combi.push_back(nums[i]);
            subsets(res,combi,nums,i+1);
            combi.pop_back();
        }
    }
};