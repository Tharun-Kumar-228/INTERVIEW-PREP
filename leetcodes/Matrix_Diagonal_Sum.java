class Solution {
    public int diagonalSum(int[][] mat) {
        int sum = 0,n=mat.length;
        for(int i = 0,j=0;  i<n && j<n;  i++,j++){
            sum += mat[i][j];
        }
        for(int i = 0,j=n-1;  i<n && j>=0;  i++,j--){
            sum += mat[i][j];
        }
        if(n%2 ==1){
            sum-= mat[n/2][n/2];
        }
        return sum;
    }
}