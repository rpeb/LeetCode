class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;
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
                    if (s.find(temp) == s.end()) {
                        res.push_back(temp);
                        s.insert(temp);
                    }
                    j++;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
            // i++;
        }
        return res;
    }
};