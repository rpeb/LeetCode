class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPriceSoFar = prices[0];
        int maxProfitSoFar = INT_MIN;
        for (int& price: prices) {
            minPriceSoFar = min(minPriceSoFar, price);
            maxProfitSoFar = max(maxProfitSoFar, price - minPriceSoFar);
        }
        return maxProfitSoFar;
    }
};