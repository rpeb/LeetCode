class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return;
        int i = n-1;
        while (i > 0 && nums[i-1] >= nums[i]) {
            i--;
        }
        if (i == 0) {
            reverse(nums.begin(), nums.end());
        } else {
            int j = i;
            i--;
            int mx = INT_MAX, g = i;
            while (j < n) {
                if (nums[j] > nums[i] && nums[j] <= mx) {
                    mx = nums[j];
                    g = j;
                }
                j++;
            }
            swap(nums[i], nums[g]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};