class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            vector<int> lastInterval = res.back();
            vector<int> currentInterval = intervals[i];
            
            if (lastInterval[1] >= currentInterval[0]) {
                res.pop_back();
                vector<int> temp(2);
                temp[0] = lastInterval[0];
                temp[1] = max(currentInterval[1], lastInterval[1]);
                res.push_back(temp);
            } else {
                res.push_back(currentInterval);
            }
        }
        return res;
    }
};