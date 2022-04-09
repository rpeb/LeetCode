class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> nmap;
        for (int num: nums) {
            nmap[num]++;
        }
        
        // to store pair of frequency and num,
        // and find k-largest frequencies
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minq;
        
        for (auto it = nmap.begin(); it != nmap.end(); ++it) {
            // forming pair from values in map
            int num = it->first;
            int frequency = it->second;
            pair<int,int> p = {frequency, num};
            
            // push pair in min_queue
            minq.push(p);
            
            // only store k (max or min guaranteed by heap)
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