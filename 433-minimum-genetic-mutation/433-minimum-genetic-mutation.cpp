class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> validGeneMutations(bank.begin(), bank.end());
        queue<string> geneMutations;
        geneMutations.push(start);
        int depth = 0, lsize = 0;
        while (!geneMutations.empty()) {
            int lsize = geneMutations.size();
            while (lsize--) {
                string geneMutation = geneMutations.front();
                if (geneMutation == end) 
                    return depth;
                geneMutations.pop();
                for (int i = 0; i < 8; ++i) {
                    string tmp = geneMutation;
                    for (char c: {'A','C','G','T'}) {
                        tmp[i] = c;
                        if (validGeneMutations.find(tmp) != validGeneMutations.end()) {
                            geneMutations.push(tmp);
                            validGeneMutations.erase(tmp);
                        }
                    }
                }
            }
            depth++;
        }
        return -1;
    }
};