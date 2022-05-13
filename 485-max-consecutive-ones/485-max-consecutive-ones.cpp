class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, res = 0;
        for (int num: nums) {
            if (num == 1) {
                res = max(++count, res);
            } else {
                count = 0;
            }
        }
        return res;
    }
};