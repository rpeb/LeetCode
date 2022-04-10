class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> vs, vt;
        for (char c: s) {
            if (c != '#') {
                vs.push_back(c);
            } else {
                if (!vs.empty())
                    vs.pop_back();
            }
        }
        for (char c: t) {
            if (c != '#') {
                vt.push_back(c);
            } else {
                if (!vt.empty())
                    vt.pop_back();
            }
        }
        return vs == vt;
    }
};