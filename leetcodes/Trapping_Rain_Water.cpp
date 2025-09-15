class Solution {
public:
    int trap(vector<int>& height) {
        // int res =0;
        // int n = height.size();
        // int lmax[n];
        // int rmax[n];
        // lmax[0]=height[0];
        // rmax[n-1] = height[n-1];
        // for(int i=1;i<n;i++)
        //     lmax[i] = max(lmax[i-1],height[i]);
        // for(int i = n-2;i>=0;i--)
        //     rmax[i]=max(rmax[i+1],height[i]);
        // for(int i=0;i<n;i++)
        //     res+=min(lmax[i],rmax[i])-height[i];
        // return res;



    int n = height.size();
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int res = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                res += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                res += rightMax - height[right];
            right--;
        }
    }

    return res;
    }
};