class Solution {
    static bool comp(vector<int> &a, vector<int> &b) {
          if (a[0] == b[0]) {
               return a[1] > b[1];
          }
          return a[0] < b[0];
     }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp);
        int n = properties.size();
        int maxTillNow = INT_MIN; 
        int weak = 0;
        for (int i = n - 1; i >= 0; i--) {
           if (properties[i][1] < maxTillNow)
                weak++;
           maxTillNow = max(maxTillNow, properties[i][1]);
        }
        return weak;
    }
};