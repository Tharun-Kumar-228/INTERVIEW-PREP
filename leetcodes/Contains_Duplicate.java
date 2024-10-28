class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> set1 = new HashSet<>();
        for(int n : nums)
        {
            if(set1.contains(n))
            {
                return true;
            }
            set1.add(n);
        }
        return false;
    }
}