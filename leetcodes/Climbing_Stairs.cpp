class Solution {
public:
    // int climbStairs(int n) {
        // vector<int>memo(n+1,-1);
        // return climbStairs(n,memo);
    // }
    // int climbStairs(int n,vector<int>&memo){
    //     if(memo[n]!=-1) return memo[n];
    //     if(n<=2) return memo[n]=n; // if(n<2) return memo[n]=1;
    //     return memo[n]=climbStairs(n-1,memo)+climbStairs(n-2,memo);
    // }



    // int climbStairs(int n){
    //     vector<int> dp(n+1,0);
    //     if(n<=2) return n;
    //     dp[1] =1 ;
    //     dp[2]=2;
    //     for(int i=3;i<=n;i++){
    //         dp[i]=dp[i-1]+dp[i-2];
        
    //     }
    //     return dp[n];
    // }


    
    int climbStairs(int n){
        if(n<=2) return n;
       int t1 =1 ;
       int t2=2;
       int res;
        for(int i=3;i<=n;i++,t1=t2,t2=res){
            res = t1+t2;
        }
        return res;
    }
};