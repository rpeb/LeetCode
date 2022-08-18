class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq;
        priority_queue<int> pq;
        int n = arr.size();
        for (int a: arr) {
            freq[a]++;
        }
        for (auto f: freq) {
            pq.push(f.second);
        }
        int removed = 0;
        int ans = 0;
        while (removed * 2 < n) {
            removed += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};