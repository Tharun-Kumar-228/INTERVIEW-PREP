class Solution {
public:
    int splitArray(vector<int>& nums) {
        int n = nums.size();

       
        vector<int> plomaresto = nums;

       
        vector<bool> inc(n, false);
        inc[0] = true;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1] && inc[i-1]) {
                inc[i] = true;
            } else {
                inc[i] = false;
            }
        }


        vector<bool> dec(n, false);
        dec[n-1] = true;
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] > nums[i+1] && dec[i+1]) {
                dec[i] = true;
            } else {
                dec[i] = false;
            }
        }

        
        vector<long long> prefix(n), suffix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) prefix[i] = prefix[i-1] + nums[i];
        suffix[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) suffix[i] = suffix[i+1] + nums[i];

       
        long long ans = LLONG_MAX;
        for (int i = 0; i < n-1; i++) {
            if (inc[i] && dec[i+1]) {
                long long diff = llabs(prefix[i] - suffix[i+1]);
                ans = min(ans, diff);
            }
        }

        return (ans == LLONG_MAX ? -1 : (int)ans);
    }
};
