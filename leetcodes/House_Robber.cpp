class Solution {
public:
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int>memo(n,-1);
    //     return rob(nums,n-1,memo);
    // }
    // int rob(vector<int>& nums,int n,vector<int>&memo){
    //     if(memo[n]!=-1 ) return memo[n];
    //     if(n==0) return memo[n]= nums[0];
    //     if(n==1) return memo[n] = max(nums[0],nums[1]);
    //     return memo[n]= max(nums[n]+rob(nums,n-2,memo),rob(nums,n-1,memo));
    // }
    int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n, 0);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
    }

    return dp[n-1];
}
};