class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        long sum1toN = n & 1 ? n * ((n + 1) / 2) : (n / 2) * (n + 1);
        for (int &num : nums) {
            sum += num;
        }
        set<int> numsSet(nums.begin(), nums.end());
        int sumOfDistinct = 0;
        for (int num: numsSet) {
            sumOfDistinct += num;
        }
        int repeated = sum - sumOfDistinct;
        int missing = sum1toN - sumOfDistinct;
        return {repeated, missing};
    }
};