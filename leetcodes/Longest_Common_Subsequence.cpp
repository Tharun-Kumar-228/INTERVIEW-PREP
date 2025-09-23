class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length();
        int l2 = text2.length();
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]= 1+ dp[i-1][j-1];
                else  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[l1][l2];
        // vector<vector<int>> memo(l1,vector<int>(l2,-1));
        // return longestCommonSubsequence(l1-1,l2-1,text1,text2,memo);
    }
    // int longestCommonSubsequence(int l1,int l2,string &text1,string &text2,vector<vector<int>> &memo){

    //     if(l1 == -1) return 0;
    //     if(l2 == -1) return 0;
    //     if(memo[l1][l2] != -1) return memo[l1][l2];
    //     if(text1[l1]==text2[l2]) return memo[l1][l2] = 1+longestCommonSubsequence(l1-1,l2-1,text1,text2,memo);
    //     return memo[l1][l2]= max(longestCommonSubsequence(l1-1,l2,text1,text2,memo),longestCommonSubsequence(l1,l2-1,text1,text2,memo));

    // }
};