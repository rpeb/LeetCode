class Solution {
public:
    void combinationSumHelper(vector<int>& c, int target, int sum, int idx, vector<int>& v, vector<vector<int>>& ans) {
        if (idx >= c.size()) return;
        if (sum + c[idx] == target) {
            v.push_back(c[idx]);
            ans.push_back(v);
            return;
        }
        if (sum + c[idx] < target) {
            vector<int> tmp1 = v;
            vector<int> tmp2 = v;
            tmp2.push_back(c[idx]);
            combinationSumHelper(c,target,sum+c[idx],idx,tmp2,ans);
            combinationSumHelper(c,target,sum,idx+1,tmp1,ans);
        } else {
            combinationSumHelper(c,target,sum,idx+1,v,ans);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        vector<vector<int>> ans;
        combinationSumHelper(candidates,target,0,0,v,ans);
        return ans;
    }
};