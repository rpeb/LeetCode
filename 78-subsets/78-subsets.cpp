class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        subsets.push_back({});
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int subsetSize = subsets.size();
            for (int j = 0; j < subsetSize; ++j) {
                vector<int> tmp = subsets[j];
                tmp.push_back(nums[i]);
                subsets.push_back(tmp);
            }
        }
        return subsets;
    }
};