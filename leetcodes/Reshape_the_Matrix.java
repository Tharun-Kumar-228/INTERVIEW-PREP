class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        // int m = mat.length,n=mat[0].length;
        // if(m*n != r*c){
        //     return mat;
        // }else{
        //     int k=0;
        //     int arr[] = new int[m*n];
        //     for(int i=0;i<m;i++){
        //         for(int j=0;j<n;j++){
        //              arr[k]=mat[i][j];
        //              k++;
        //         }
        //     }
        //     k=0;
        //     int a[][] = new int[r][c];
        //      for(int i=0;i<r;i++){
        //         for(int j=0;j<c;j++){
        //              a[i][j]=arr[k];
        //              k++;
        //         }
        //     }
        //     return a;



        int m = mat.length,n=mat[0].length;
        int arr[][]= new int[r][c];
        if(m*n != r*c){
            return mat;
        }else{
            int row=0,col=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(col==c){
                        col=0;
                        row++;
                    }
                    arr[row][col] = mat[i][j];
                    col++;
                }
            }
        }
        return arr;
    }
}