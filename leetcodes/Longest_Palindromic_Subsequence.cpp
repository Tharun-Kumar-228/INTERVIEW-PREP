class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int r = s.length()-1;
        int l=0;
        vector<vector<int>> memo(r+1,vector<int>(r+1,-1));
        return longestPalindromeSubseq(l,r,s,memo);
    }
    int longestPalindromeSubseq(int l,int r, string &s, vector<vector<int>> &memo) {
        if(l > r) return 0;
        if(l==r) return 1;
        if(memo[l][r]!=-1) return memo[l][r];
        if(s[l]==s[r]) return memo[l][r]=2+longestPalindromeSubseq(l+1,r-1,s,memo);
        return memo[l][r]=max(longestPalindromeSubseq(l+1,r,s,memo),longestPalindromeSubseq(l,r-1,s,memo));
    }
};