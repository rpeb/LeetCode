class Solution {
void populateStackFromVector(vector<string>& v, stack<string>& st) {
    for (auto x: v) {
            if (x == "." || (x == ".." && st.empty())) {
                continue;
            } else if (x == "..") {
                st.pop();
            } else {
                st.push(x);
            }
        }
}
    void parsePathToDirectories(string& path, vector<string>& v) {
        string tmp;
        int n = path.size();
        for (int i = 0; i < n; ++i) {
            if (path[i] != '/') {
                tmp += path[i];
            } else {
                if (!tmp.empty())
                    v.push_back(tmp);
                tmp = "";
            }
        }
        if (!tmp.empty()) {
            v.push_back(tmp);
        }
    }
public:
    string simplifyPath(string path) {
        vector<string> v;
        stack<string> st;
        parsePathToDirectories(path,v);
        populateStackFromVector(v,st);
        string tmp;
        while (!st.empty()) {
            tmp = st.top() + "/" + tmp;
            st.pop();
        }
        tmp = "/" + tmp;
        return (tmp=="/") ? "/" : tmp.substr(0,tmp.size()-1);
    }
};