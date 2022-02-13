class Solution {
private:
    bool isLowerCase(char c) {
        return (c >= 'a' && c <= 'z'); 
    }
    bool isUpperCase(char c) {
        return (c >= 'A' && c <= 'Z');
    }
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        vector<string> permutations;
        unordered_set<string> setOfPermutationsOccured;
        queue<string> bfsQueue;
        bfsQueue.push(s);
        setOfPermutationsOccured.insert(s);
        // permutations.push_back(s);
        int lsize = 0;
        while (!bfsQueue.empty()) {
            lsize = bfsQueue.size();
            while(lsize--) {
                string str = bfsQueue.front();
                // cout << "str = " << str << " ";
                permutations.push_back(str);   
                bfsQueue.pop();
                for (int i = 0; i < n; ++i) {
                    string tmp = str;
                    if (isLowerCase(tmp[i])) {
                        tmp[i] -= 32;
                    } else if (isUpperCase(tmp[i])) {
                        tmp[i] += 32;  
                    } 
                    if (setOfPermutationsOccured.find(tmp) == setOfPermutationsOccured.end()) {
                        bfsQueue.push(tmp);
                        setOfPermutationsOccured.insert(tmp);
                    }
                }
            }
        }
        return permutations;
    }
};