class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        n = n / 2;
        unordered_map<int,int> mp;
        for (int t: nums) {
            mp[t]++;
        }
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (it->second > n) {
                return it->first;
            }
        }
        return 1;
    }
};