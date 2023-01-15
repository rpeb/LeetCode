class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int num: nums) {
            mp[num]++;
        }
        sort(nums.begin(),nums.end(),[mp](int a, int b) {
            if (mp.at(a) == mp.at(b)) {
                return a > b;
            }
            return mp.at(a) < mp.at(b);
        });
        return nums;
    }
};