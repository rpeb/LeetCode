class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int maxAreaSoFar = -1;
        int area, a, b;
        while (l < r) {
            a = height[l];
            b = height[r];
            if (a < b) {
                area = a * (r - l);
                l++;
            } else {
                area = b * (r - l);
                r--;
            }
            maxAreaSoFar = max(maxAreaSoFar, area);
        }
        return maxAreaSoFar;
    }
};