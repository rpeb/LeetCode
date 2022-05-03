class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1)
            return {{1}};
        if (numRows == 2) 
            return {{1},{1,1}};
        
        // prepare first 2 rows
        vector<vector<int>> base;
        base.push_back({1});
        base.push_back({1,1});
        while (numRows > 2) {
            vector<int> lastRow = base.back();
            int n = lastRow.size();
            vector<int> tmp;
            tmp.push_back(1);
            for (int i = 0; i < n-1; ++i) {
                tmp.push_back(lastRow[i] + lastRow[i+1]);
            }
            tmp.push_back(1);
            base.push_back(tmp);
            numRows--;
        }
        return base;
    }
};