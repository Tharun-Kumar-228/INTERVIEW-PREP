class Solution {
    public int[] replaceElements(int[] arr) {
        int a = arr.length;
        int prev = -1;
        for(int i = a-1;i>=0;i--){
            int curr  = arr[i];
            arr[i] = prev;
            if(prev < curr ){
                prev = curr;
            }
        }
        return arr;
    }
}