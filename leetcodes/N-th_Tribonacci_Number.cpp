class Solution {
public:
    int tribonacci(int n,vector<int>&memo) {
        if(memo[n]!=-1) return memo[n];
        if(n<2) return memo[n]=n;
        if(n==2) return memo[n]=1;
        return memo[n] = tribonacci(n-1,memo)+tribonacci(n-2,memo)+tribonacci(n-3,memo);
    }
    int tribonacci(int n){
        vector <int> memo(n+1,-1);
        return tribonacci(n,memo);
    }

};