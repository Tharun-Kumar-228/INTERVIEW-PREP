class Solution {
    public int mySqrt(int x) {
         double sq = Math.sqrt(x);
        int res = (int) Math.floor(sq);
        return res;
    }
}