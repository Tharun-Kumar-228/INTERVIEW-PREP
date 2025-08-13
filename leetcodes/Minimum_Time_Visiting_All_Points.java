class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int dist = 0;
        for (int i = 1; i < points.length; i++) {
            int dx = points[i][0] - points[i - 1][0];
            int dy = points[i][1] - points[i - 1][1];
            if (dx < 0) dx = -dx;
            if (dy < 0) dy = -dy;
            dist += dx >= dy ? dx : dy;
        }
        return dist;
    }
}
