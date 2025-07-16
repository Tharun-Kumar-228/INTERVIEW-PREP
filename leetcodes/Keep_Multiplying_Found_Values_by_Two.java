class Solution {
    public int findFinalValue(int[] nums, int original) {
        // int i=0;
        // while(i<nums.length){
        //     if(nums[i] == original){
        //         original *=2;
        //         i=-1;
        //     }
        // i++;   
        // }
        // return original;
        //Using Recursion
        for(int i=0;i<nums.length;i++){
        if(nums[i]==original){
            original*=2;
              return findFinalValue(nums, original);
        }
        
       } 
       return original;
    }
}