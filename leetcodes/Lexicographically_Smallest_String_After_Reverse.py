class Solution:
    def lexSmallest(self, s: str) -> str:
        best = s
        n = len(s)
        for k in range(1, n + 1):
            first_rev = s[:k][::-1] + s[k:]
            last_rev = s[:-k] + s[-k:][::-1]
            best = min(best, first_rev, last_rev)
        return best