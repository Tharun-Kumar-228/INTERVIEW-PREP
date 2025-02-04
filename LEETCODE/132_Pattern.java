class Solution {
    public boolean find132pattern(int[] nums) {
        for(int k =0;k<nums.length;k++){
            for(int j=0;j<k;j++){
                for(int i=0;i<j;i++){
                    if(nums[i]<nums[k] && nums[k]<nums[j]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
}