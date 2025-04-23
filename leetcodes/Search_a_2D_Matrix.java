class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0)
            return false;

        int rows = matrix.length;
        int cols = matrix[0].length;
        int start = 0;
        int end = rows * cols - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            int midElement = matrix[mid / cols][mid % cols];

            if (midElement == target) {
                return true;
            } else if (midElement < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
}
