class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> m;
        for (int& a: arr) {
            m[a]++;
        }
        // 3 -> 4
        // 5 -> 3
        // 2 -> 2
        // 7 -> 1
        
        // max heap
        priority_queue<int> pq;
        for (auto x: m) {
            pq.push(x.second);
        }
        int ans = 0, removed = 0;
        while (removed * 2 < n) {
            removed += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};