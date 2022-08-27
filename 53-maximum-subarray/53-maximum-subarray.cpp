class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSumSoFar = 0;
        int res = INT_MIN;
        bool allNegative = true;
        int maxElement = nums[0];
        for (int& num: nums) {
            if (num >= 0) allNegative = false;
            maxSumSoFar += num;
            maxSumSoFar = max(0, maxSumSoFar);
            res = max(res, maxSumSoFar);
            
            maxElement = max(maxElement, num);
        }
        return allNegative ? maxElement: res;
    }
};