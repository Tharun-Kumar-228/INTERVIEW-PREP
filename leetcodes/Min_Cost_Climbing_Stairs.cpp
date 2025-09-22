class Solution {
public:
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int> memo(n, -1);

    //     int res = min(costclimb(n-1, cost, memo), costclimb(n-2, cost, memo));
    //     return res;
    // }

    // int costclimb(int n, vector<int>& cost, vector<int>& memo) {
    //     if (n < 0) return 0;
    //     if (n == 0 || n == 1) return cost[n];  

    //     if (memo[n] != -1) return memo[n];    

    //     return memo[n] = cost[n] + min(costclimb(n-1, cost, memo), costclimb(n-2, cost, memo));
    // }



    // int minCostClimbingStairs(vector<int>& cost){
    //     int n = cost.size();
    //     vector <int> memo(n,-1);
    //     memo[0]= cost[0];
    //     memo[1]= cost[1];
    //     for(int i=2;i<cost.size();i++){
    //         memo[i]=cost[i]+min(memo[i-1],memo[i-2]);
    //     }
    //     return min(memo[n-1],memo[n-2]);
    // }


    int minCostClimbingStairs(vector<int>& cost){
        int t1 = cost[0];
        int t2 = cost[1];
        int t3;
        for(int i=2;i<cost.size();i++){
            t3 = cost[i]+ min(t1,t2);
            t1=t2;
            t2=t3;
        }
        return min(t1,t2);
    }
};
