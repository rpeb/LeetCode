class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = height.front();
        int maxHeightIndex = max_element(height.begin(), height.end()) - height.begin();
        int totalWaterTrapped = 0;
        for (int i = 1; i < maxHeightIndex; ++i) {
            if (height[i] >= left) {
                left = height[i];
            } else {
                totalWaterTrapped += left - height[i];
            }
        }
        int right = height.back();
        for (int i = n-2; i > maxHeightIndex; --i) {
            if (height[i] > right) {
                right = height[i];
            } else {
                totalWaterTrapped += right - height[i];
            }
        }
        return totalWaterTrapped;
    }
};