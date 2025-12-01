class Solution {
    public long maxRunTime(int n, int[] batteries) {
        long sum = Arrays.stream(batteries).sum();
        return sum / n;
    }
}
