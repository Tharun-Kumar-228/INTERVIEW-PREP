import java.util.ArrayList;
class Solution {
    public int removeElement(int[] nums, int val) {
        ArrayList<Integer> arr = new ArrayList<>();
        for (int n : nums) {
            if (n != val) {
                arr.add(n);
            }
        }
        
        for (int i = 0; i < arr.size(); i++) {
            nums[i] = arr.get(i);
        }
        return arr.size();
    }
}
