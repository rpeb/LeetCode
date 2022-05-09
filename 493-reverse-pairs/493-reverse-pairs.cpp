class Solution {
public:
    int merge(vector<int>& left, vector<int>& right, vector<int>& v) {
        int leftSize = left.size();
        int rightSize = right.size();
        int i = 0, j = 0, k = 0;
        int revPairs = 0;
        while (i < leftSize && j < rightSize) {
            if ((long)left[i] > (long) 2 * right[j]) {
                revPairs += leftSize - i;
                j++;
            } else {
                i++;
            }
        }
        i = 0;
        j = 0;
        while (i < leftSize && j < rightSize) {
            if (left[i] <= right[j]) {
                v[k] = left[i];
                i++;
            } else {
                v[k] = right[j];
                j++; 
            }
            k++;
        }
        while (i < leftSize) {
            v[k++] = left[i++];
        }
        while (j < rightSize) {
            v[k++] = right[j++];
        }
        return revPairs;
    }
    
    int mergeSort(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        int mid = n / 2;
        vector<int> left, right;
        int revPairs = 0;
        for (int i = 0; i < n; ++i) {
            if (i < mid) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        revPairs += mergeSort(left);
        revPairs += mergeSort(right);
        revPairs += merge(left, right, nums);
        return revPairs;
    }
    
    int reversePairs(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        return mergeSort(nums);
    }
};

// left 2,3,4
// right 1,5