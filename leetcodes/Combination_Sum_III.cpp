class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>>res;
        vector<int> combi;
        int currsum=0;
        combsum(k,n,combi,res,arr,0,currsum);
        return res;
    }
    void combsum(int &size,int &target,vector<int> &combi,vector<vector<int>> &res,vector<int>&arr,int start,int sum){
        
        if(sum == target && combi.size()==size){
            res.push_back(combi);
            return;
        }
        if(sum>target) return;
        for(int i=start;i<arr.size();i++){
            combi.push_back(arr[i]);
            sum+=arr[i];
            combsum(size,target,combi,res,arr,i+1,sum);
            sum-=arr[i];
            combi.pop_back();
        }
    }
};