class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int duplicatesSoFar = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i-1]) {
                duplicatesSoFar++;
            } else {
                nums[i - duplicatesSoFar] = nums[i];
            }
        }
        return n - duplicatesSoFar;
    }
};