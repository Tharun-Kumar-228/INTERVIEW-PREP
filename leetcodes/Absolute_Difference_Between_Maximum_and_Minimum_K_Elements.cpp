class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
         sort(nums.begin(), nums.end());
        int smallSum = 0, largeSum = 0;
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            smallSum += nums[i];
            largeSum += nums[n - 1 - i];
        }
        return abs(largeSum - smallSum);
    }
};