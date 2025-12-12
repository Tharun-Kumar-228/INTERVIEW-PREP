class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int third = INT_MIN;
        vector<int> st;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < third) return true;
            while (!st.empty() && nums[i] > st.back()) {
                third = st.back();
                st.pop_back();
            }
            st.push_back(nums[i]);
        }
        return false;
    }
};