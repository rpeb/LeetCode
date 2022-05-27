class Solution {
public:
    void solve(vector<int>& nums, vector<int> temp, int i, int target, vector<vector<int>>& res) {
        // base
        if (i == nums.size()) {
            if (target == 0) {
                res.push_back(temp);
            }
            return;
        }
        
        if (nums[i] > target) {
            solve(nums, temp, i + 1, target, res);
        } else {
            // exclude
            solve(nums, temp, i + 1, target, res);
            // include
            temp.push_back(nums[i]);
            solve(nums, temp, i, target - nums[i], res);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int i = 0;
        solve(nums, temp, i, target, res);
        return res;
    }
};