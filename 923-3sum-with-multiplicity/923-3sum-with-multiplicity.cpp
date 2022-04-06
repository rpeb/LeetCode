class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int,int> m;
        int res = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            // add the frequency of target-arr[i] to result.
            // arr[i] adds up to target-arr[i] to give target.
            res = (res + m[target-arr[i]]) % mod;
            
            // maintain frequency of sum of each pair
            for (int j = 0; j < i; ++j) 
                m[arr[i] + arr[j]]++;
        }
        return res;
    }
};