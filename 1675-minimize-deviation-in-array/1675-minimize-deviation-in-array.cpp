class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int minVal = numeric_limits<int>::max();
        for (int i: nums) {
            if (i & 1) i *= 2;
            minVal = min(minVal, i);
            pq.push(i);
        }
        int diff = numeric_limits<int>::max();
        while (!(pq.top() & 1)) {
            int maxVal = pq.top();
            pq.pop();
            diff = min(diff, maxVal - minVal);
            int halfMax = maxVal/2;
            minVal = min(minVal, halfMax);
            pq.push(halfMax);
        }
        return min(diff, pq.top()-minVal);
    }
};