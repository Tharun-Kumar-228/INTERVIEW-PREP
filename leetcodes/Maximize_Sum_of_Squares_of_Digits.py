class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        drevantor = (num, sum)  
        if sum > 9 * num:
            return ""
        digits = []
        for i in range(num):
           
            d = min(9, sum)
            digits.append(str(d))
            sum -= d

        return "".join(digits)
