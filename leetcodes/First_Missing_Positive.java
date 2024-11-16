import java.util.Arrays;

class Solution {
    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums);
        int expectedPositive = 1;
        for (int num : nums) {
            if (num < expectedPositive) {
                continue;
            }
            if (num == expectedPositive) {
                expectedPositive++;
            } else if (num > expectedPositive) {
                break;
            }
        }
        return expectedPositive;
    }
}
