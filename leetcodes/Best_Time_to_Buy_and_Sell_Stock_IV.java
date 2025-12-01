class Solution {
    public int maxProfit(int k,int[] prices) {
        int n = prices.length;
        Integer[][][] dp = new Integer[n][2][k+1];
        return helper(prices, 0, 0, 0, dp,k);
    }

    public int helper(int[] prices, int i, int hold, int sells, Integer[][][] dp,int max_sells) {
        if (i == prices.length) return 0;
        if (sells == max_sells) return 0; 
        if (dp[i][hold][sells] != null) return dp[i][hold][sells];

        int ans;
        if (hold == 0) {
            int buy = -prices[i] + helper(prices, i + 1, 1, sells, dp,max_sells);
            int skip = helper(prices, i + 1, 0, sells, dp,max_sells);

            ans = Math.max(buy, skip);
        } 
        else { 
            
            int sell = prices[i] + helper(prices, i + 1, 0, sells + 1, dp,max_sells);

           
            int skip = helper(prices, i + 1, 1, sells, dp,max_sells);

            ans = Math.max(sell, skip);
        }

        dp[i][hold][sells] = ans;
        return ans;
    }
}
