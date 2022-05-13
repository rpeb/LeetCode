class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        // if (n == 1) return nums[0] == 1;
        int res = 0, i = 0;
        int count = 0, f;
        while (i < n) {
            f = 1;
            int k = nums[i];
            if (f & k) {
                // if (i == n-1 && count > 0) {
                //     res = max(res,count) + 1;
                // }
                count++;
                i++;
            } else {
                res = max(res,count);
                count = 0;
                int j = i;
                while (j < n && (f & nums[j] == 0)) j++;
                i = j;
            }
        }
        if (nums.back() == 1) {
            res = max(res, count);
        }
        return res;
    }
};