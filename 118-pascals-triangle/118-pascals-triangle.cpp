class Solution {
public:
    vector<vector<int>> generate(int rows) {
        vector<vector<int>> res;
        res.push_back({1});
        if (rows == 1) {
            return res;
        }
        res.push_back({1,1});
        if (rows == 2) {
            return res;
        }
        for (int i = 0; i < rows - 2; ++i) {
            vector<int> last = res.back();
            int lastSize = last.size();
            vector<int> curr(lastSize + 1);
            curr[0] = 1;
            for (int j = 1; j < lastSize; ++j) {
                curr[j] = last[j-1] + last[j];
            }
            curr[lastSize] = 1;
            res.push_back(curr);
        }
        return res;
    }
};