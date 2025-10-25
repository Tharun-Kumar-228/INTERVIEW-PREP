class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        tup = (nums1, nums2)

        n = len(nums1)
        m = len(nums2)

        @lru_cache(None)
        def rec(i, j):
            if i == n:
                if j == m - 1:
                    return 1
                else:
                    return float('inf')
            if j >= m:
                return float('inf')
            
            skip = 1 + rec(i, j + 1)
            cost = abs(nums1[i] - nums2[j]) + rec(i + 1, j + 1)
            
            return min(skip, cost)

        return rec(0, 0)