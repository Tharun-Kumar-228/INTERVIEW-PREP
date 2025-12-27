class Solution {
    public long maximumTripletValue(int[] arr) {
        long maxLeft = arr[0];
        long bestDiff = 0;
        long ans = 0;

        for (int i = 0; i < arr.length; i++) {
            ans = Math.max(ans, bestDiff * arr[i]);
            bestDiff = Math.max(bestDiff, maxLeft - arr[i]);
            maxLeft = Math.max(maxLeft, arr[i]);
        }

        return ans;
    }
}
