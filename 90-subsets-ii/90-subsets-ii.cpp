class Solution {
public:
    void solve(vector<int>& nums, vector<int> temp, int idx, vector<vector<int>>& res) {
        // base case
        res.push_back(temp);
        
        for (int i = idx; i < nums.size(); ++i) {
            if (idx != i && nums[i] == nums[i-1]) continue;
            // choose
            temp.push_back(nums[i]);
            solve(nums,temp,i+1,res);
            // unpick
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int idx = 0;
        vector<vector<int>> res;
        vector<int> temp;
        solve(nums, temp, idx, res);
        return res;
    }
};