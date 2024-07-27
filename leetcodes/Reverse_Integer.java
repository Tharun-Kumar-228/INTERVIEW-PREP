class Solution {
    public int reverse(int x) {
        long n1 = 0;
        int n2 = Math.abs(x);
        while (n2 > 0) {
            int rem = n2 % 10;
            n1 = n1*10+rem;
            n2/=10;
        }
        if(Integer.MAX_VALUE<n1)
        return 0;
        if(x<0)
        return -(int)n1;
        else
        return (int)n1;
    }
}