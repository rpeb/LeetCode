class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        int m = INT_MIN;
        bool allNegative = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 0) {
                allNegative = false;
            }
            s += nums[i];
            if (s < 0)
                s = 0;
            m = max(m,s);
        }
        return allNegative ? *max_element(nums.begin(), nums.end()) : m;
    }
};