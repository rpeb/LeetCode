class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res;
        for (int i = 0; i < n1; ++i) {
            bool found = false;
            int j = 0;
            while (j < n2 && !found) {
                if (nums2[j] == nums1[i]) {
                    found = true;
                }
                j++;
            }
            while (j < n2 && nums2[j] < nums1[i]) {
                j++;
            }   
            int nextGreaterInt = (j == n2) ? -1 : nums2[j];
            res.push_back(nextGreaterInt);
        }
        return res;
    }
};