class Solution {
public:
    int minInsertions(string s) {
        int l=0;
        int r=s.length();
        vector<vector<int>>memo(r,vector<int>(r,-1));
        return minInsertion(l,r-1,s,memo);
    }
    int minInsertion(int l,int r,string  &s, vector<vector<int>>&memo){
        if(memo[l][r]!=-1) return memo[l][r];
        if(l==r) return memo[l][r]= 0;
        if(l>r) return memo[l][r]=0;
       
        if(s[l] == s[r]) return memo[l][r]=minInsertion(l+1,r-1,s,memo);
        return memo[l][r]=1+min({minInsertion(l+1,r,s,memo),minInsertion(l,r-1,s,memo)});
    }
};

