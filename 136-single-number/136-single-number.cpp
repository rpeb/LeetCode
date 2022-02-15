class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNumber = 0;
        for (int& num: nums) {
            singleNumber ^= num;
        }
        return singleNumber;
    }
};