class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> idx;
        int n = temperatures.size();
        vector<int> res(n,0);
        idx.push(0);
        
        for (int i = 1; i < n; ++i) {
            while (!idx.empty() && temperatures[i] > temperatures[idx.top()]) {
                res[idx.top()] = i - idx.top();
                idx.pop();
            }
            idx.push(i);
        }
        return res;
    }
};