class Solution {
public:
    int edgeScore(vector<int>& edges) {
        unordered_map<long,long> edgeScores;
        long maxEdgeScore = 0;
        int ans;
        int n = edges.size();
        for (int i = 0; i < n; ++i) {
            edgeScores[edges[i]] += i;
            if (edgeScores[edges[i]] > maxEdgeScore) {
                maxEdgeScore = edgeScores[edges[i]];
                ans = edges[i];
            } else if (edgeScores[edges[i]] == maxEdgeScore) {
                ans = min(ans, edges[i]);
            }
        }
        return ans;
    }
};