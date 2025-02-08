class Solution {
    public boolean isPerfectSquare(int num) {
        int maxN = (int) Math.sqrt(Integer.MAX_VALUE); 
        long[] squares = new long[maxN + 1]; 

        for (int i = 0; i <= maxN; i++) {
            squares[i] = (long) i * i; 
        }
        for (long n : squares) {
            if (n == (long)num) {
                return true; 
            }
        }
        return false;
    }
}