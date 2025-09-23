class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return minDistance(word1,word2,m-1,n-1,memo);
    }
    int minDistance(string &s,string &t,int i,int j, vector<vector<int>> &memo){
        if(j<0) return i+1;
        if(i<0) return j+1;
        if(memo[i][j]!=-1) return memo[i][j];
        if(s[i]==t[j]) return memo[i][j]=minDistance(s,t,i-1,j-1,memo);
        return memo[i][j]=1+min( {minDistance(s,t,i-1,j,memo),minDistance(s,t,i,j-1,memo),minDistance(s,t,i-1,j-1,memo)});
    }
};