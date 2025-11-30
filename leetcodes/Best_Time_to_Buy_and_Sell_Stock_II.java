class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        Integer[][] dp = new Integer[n][2];
        return helper(prices, 0, 0, dp); 
    }

    public int helper(int[] prices, int i, int hold, Integer[][] dp) {
        if (i == prices.length) return 0;
        if (dp[i][hold] != null) return dp[i][hold];

        int ans;
        if (hold == 0) {
           
            int buy = -prices[i] + helper(prices, i+1, 1, dp);
            int skip = helper(prices, i+1, 0, dp);
            ans = Math.max(buy, skip);
        } else {
           
            int sell = prices[i] + helper(prices, i+1, 0, dp);
            int skip = helper(prices, i+1, 1, dp);
            ans = Math.max(sell, skip);
        }

        return dp[i][hold] = ans;
    }
}
