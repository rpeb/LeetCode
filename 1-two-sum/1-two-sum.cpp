class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int,int> m;
        for (int i = 0; i < n; ++i) {
            m[nums[i]] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            int second = target - nums[i];
            auto it = m.find(second);
            if (it != m.end() && it->second != i) {
                res.push_back(i);
                res.push_back(it->second);
                break;
            }
        }
        return res;
    }
};