class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        int n = nums.length;
        int o_i = 1,e_i=0;
        int arr[] = new int[n];
        for(int i= 0;i<n;i++){
            if(nums[i]%2 == 0){
                arr[e_i] = nums[i];
                e_i+=2;
            }else{
                arr[o_i] = nums[i];
                o_i+=2;
            }
        }
        return arr;
    }
}