import java.util.*;
class Solution {
      public int[] sortedSquares(int[] nums) {
        ArrayList<Integer> squaredList = new ArrayList<>(nums.length);
        for (int x : nums) {
            squaredList.add(x * x);
        }
        int[] result = new int[squaredList.size()];
        for (int i = 0; i < squaredList.size(); i++) {
            result[i] = squaredList.get(i);
        }
        Arrays.sort(result);   
        return result;
    }
}