class Solution {
    public int largestAltitude(int[] gain) {
        int n = gain.length+1;
        int arr[] = new int[n];
        for(int i=1;i<n;i++){
            arr[i]= arr[i-1]+gain[i-1];
        }
        int max =0;
        for(int i=0;i<n;i++){
            if(max<arr[i]){
                max = arr[i];
            }
        }
        return max;
    }
}