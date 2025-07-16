class Solution {
    public int summer(int []nums){
        int a = 0;
        for(int b:nums){
            a+=b;
        }
        return a;
    }
    public int maximumWealth(int[][] accounts) {
        int max =-1;
        for(int arr[] : accounts){
            int tot = summer(arr);
            if(max < tot){
                max = tot;
            }
        }
        return max;
    }
}