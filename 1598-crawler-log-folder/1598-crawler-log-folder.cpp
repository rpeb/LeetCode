class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (string log: logs) {
            if (log == "./") {
                continue;
            } else if (log == "../") {
                if (depth == 0) continue;
                else depth--;
            } else {
                depth++;
            }
        }
        return depth;
    }
};