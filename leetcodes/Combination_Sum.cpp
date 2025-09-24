class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> res;
        vector<int> combi;
        int sum = 0;
        checksum(arr, tar, combi, res, sum, 0); 
        return res;
    }
    
    void checksum(vector<int> &arr, int target, vector<int>& combi,
                  vector<vector<int>>& res, int sum, int start) {
        
        if (sum == target) {
            res.push_back(combi);
            return;
        }
        if (sum > target) return; 
        
        for (int i = start; i < arr.size(); i++) {
            combi.push_back(arr[i]);
            sum += arr[i];
            checksum(arr, target, combi, res, sum, i); 
            sum -= arr[i]; 
            combi.pop_back();
        }
    }
};
