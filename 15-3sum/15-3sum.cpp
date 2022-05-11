class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = n - 1;
            vector<int> temp;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    temp = {nums[i],nums[j],nums[k]};
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