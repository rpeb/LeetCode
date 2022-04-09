class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> nmap;
        for (int num: nums) {
            nmap[num]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minq;
        
        for (auto it = nmap.begin(); it != nmap.end(); ++it) {
            int num = it->first;
            int frequency = it->second;
            pair<int,int> p = {frequency, num};
            minq.push(p);
            if (minq.size() > k) {
                minq.pop();
            }
        }
        
        vector<int> res;
        while (!minq.empty()) {
            res.push_back(minq.top().second);
            minq.pop();
        }
        
        return res;
    }
};