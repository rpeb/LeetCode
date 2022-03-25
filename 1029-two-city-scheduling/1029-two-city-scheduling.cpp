class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int numberOfPersons = costs.size();
        int res = 0;
        vector<int> diff;
        for (int i = 0; i < numberOfPersons; ++i) {
            // sending everyone to city A first
            res += costs[i][0];
            
            // seeing how much more it would cost to send to city B
            diff.push_back(costs[i][1] - costs[i][0]);
        }
  
        // sort based on the cost to send to city B from city A
        sort(diff.begin(), diff.end());
        
        // send first n people from sorted diff to city B
        for (int i = 0; i < numberOfPersons/2; ++i) {
            res += diff[i];
        }
        
        return res;
    }
};