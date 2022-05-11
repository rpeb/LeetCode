class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3) return res;
        sort(nums.begin(), nums.end());
        int i = 0, j, k;
        while (i++ < n-2) {
            int i2 = i-1;
            if (i2 > 0 && nums[i2] == nums[i2-1]) continue;
            j = i2 + 1;
            k = n - 1;
            vector<int> temp;
            while (j < k) {
                int sum = nums[i2] + nums[j] + nums[k];
                if (sum == 0) {
                    temp = {nums[i2],nums[j],nums[k]};
                    res.push_back(temp);
                    while (j < k && nums[j] == nums[j+1]) j++;
                    while (k > j && nums[k-1] == nums[k]) k--;
                    if (j < n-1) j++;
                    if (k > 0) k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return res;
    }
};