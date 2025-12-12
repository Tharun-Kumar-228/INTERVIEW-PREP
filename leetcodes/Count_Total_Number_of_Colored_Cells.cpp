class Solution {
public:
    long long coloredCells(int n) {
        // long long  x = (long long)n*(n-1)/2;
        // x*=4;
        // x=x+1;
        // return x;

        return 2LL*(n)*(n-1)+1;

    }
};