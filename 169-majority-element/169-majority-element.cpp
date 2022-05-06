class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's voting algo
        
        // step 1 - find candidate element
        int n = nums.size();
        n /= 2;
        int candidate = -1;
        int count = 0;
        for (int num: nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        // step2 - verify candidate element is majority element
        int verifyingCount = 0;
        for (int num: nums) {
            if (num == candidate) {
                verifyingCount++;
            }
        }
        return (verifyingCount > n) ? candidate : -1;
    }
};