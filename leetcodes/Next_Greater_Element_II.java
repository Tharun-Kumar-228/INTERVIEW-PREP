// class Solution {
//     public int[] nextGreaterElements(int[] nums) {
//         int n = nums.length;
//         int[] res = new int[n];
//         for (int i = 0; i < n; i++) {
//             res[i] = -1; 
//             for (int j = 1; j < n; j++) {
//                 int nextIndex = (i + j) % n;
//                 if (nums[nextIndex] > nums[i]) {
//                     res[i] = nums[nextIndex];
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// }
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        Stack <Integer> s =new Stack<>();
        int n = nums.length;
        int [] res = new int [n];
        Arrays.fill(res,-1);
        for(int i=0;i<2*n;i++){
            while(!s.empty() && nums[i%n]>nums[s.peek()]){
                res[s.pop()] = nums[i % n];
            }
            s.push(i %n);
        }
        return res;
    }
}