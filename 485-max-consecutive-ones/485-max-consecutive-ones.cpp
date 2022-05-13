class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int res = 0, i = 0;
        int count = 0, f;
        while (i < n) {
            f = 1;
            int k = nums[i];
            if (f & k) {
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
        
        res = max(res, count);
        return res;
    }
};