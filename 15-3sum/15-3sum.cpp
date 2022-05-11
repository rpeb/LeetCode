class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;
        int n = nums.size();
        if (n < 3) return res;
        sort(nums.begin(), nums.end());
        int i = 0, j, k;
        while (i < n-2) {
            j = i + 1;
            k = n - 1;
            int req = 0 - nums[i];
            vector<int> temp;
            while (j < k) {
                if (nums[j] + nums[k] == req) {
                    temp = {nums[i],nums[j],nums[k]};
                    if (s.find(temp) == s.end()) {
                        res.push_back(temp);
                        s.insert(temp);
                    }
                    j++;
                } else if (nums[j] + nums[k] < req) {
                    j++;
                } else {
                    k--;
                }
            }
            i++;
        }
        return res;
    }
};