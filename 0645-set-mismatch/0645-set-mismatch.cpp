class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        long sum1toN = n & 1 ? n * ((n + 1) / 2) : (n / 2) * (n + 1);
        for (int &num : nums) {
            sum += num;
        }
        // sum = 9
        set<int> numsSet(nums.begin(), nums.end());
        int sumOfDistinct = 0;
        for (int num: numsSet) {
            sumOfDistinct += num;
        }
        // sumOfDistinct = 7
        cout << "sum = " << sum << "\n" << "sum1toN = " << sum1toN << "\n";
        int repeated = sum - sumOfDistinct;
        int missing = sum1toN - sumOfDistinct;
        return {repeated, missing};
    }
};