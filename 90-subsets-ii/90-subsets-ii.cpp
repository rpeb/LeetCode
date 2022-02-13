class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> subsets;
        subsets.push_back({});
        vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            int subsetSize = subsets.size();
            for (int j = 0; j < subsetSize; ++j) {
                tmp = subsets[j];
                tmp.push_back(nums[i]);
                if (count(subsets.begin(),subsets.end(),tmp) == 0)
                    subsets.push_back(tmp);
            }
        }
        return subsets;
    }
};