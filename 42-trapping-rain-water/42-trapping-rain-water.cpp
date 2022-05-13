class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        int res = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] < leftMax) {
                    res += leftMax - height[l];
                } else {
                    leftMax = height[l];
                }
                l++;
            } else {
                if (height[r] < rightMax) {
                    res += rightMax - height[r];
                } else {
                    rightMax = height[r];
                }
                r--;
            }
        }
        return res;
    }
};