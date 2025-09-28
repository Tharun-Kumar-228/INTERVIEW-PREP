class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> result;
        long long place = 1;

        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                result.push_back(digit * place); // product fits in long long
            }
            n /= 10;
            place *= 10;
        }

        sort(result.rbegin(), result.rend());
        return result;
    }
};
