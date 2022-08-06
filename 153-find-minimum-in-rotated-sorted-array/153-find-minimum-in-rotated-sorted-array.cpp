class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n-1, mid;
        while (l < h) {
            if (nums[l] < nums[h]) {
                return nums[l];
            }
            mid = l + (h - l) / 2;
            if (nums[mid] >= nums[l]) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return nums[l];
    }
};