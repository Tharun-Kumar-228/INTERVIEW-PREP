class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 & j==0) dp[i][j]=grid[i][j];
                else if(i==0) dp[i][j] = dp[i][j-1]+grid[i][j];
                else if(j==0) dp[i][j] = dp[i-1][j]+grid[i][j];
                else dp[i][j] = grid[i][j]+ min(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[m-1][n-1];
        //vector<vector<int>> memo(m,vector<int>(n,-1));
        // return minPathSum(m-1,n-1,grid,memo);
    }
    // int minPathSum(int m,int n,vector<vector<int>>&grid,vector<vector<int>>&memo){
    //     if(memo[m][n]!=-1) return memo[m][n];
    //     if(m==0&&n==0) return memo[m][n] = grid[m][n];
    //     else if(m == 0) return memo[m][n] =grid[m][n]+minPathSum(m,n-1,grid,memo);
    //     else if(n==0) return memo[m][n] =grid[m][n]+minPathSum(m-1,n,grid,memo);
    //     else return memo[m][n] =grid[m][n]+ min(minPathSum(m-1,n,grid,memo),minPathSum(m,n-1,grid,memo));

    // }
};