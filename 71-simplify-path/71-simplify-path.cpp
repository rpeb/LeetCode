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
        path += "/";
        int n = path.size();
        vector<string> v;
        string tmp;
        
        for (int i = 0; i < n; ++i) {
            if (path[i] == '/') {
                if (!tmp.empty()) {
                    cout << "tmp = " << tmp << "\n";
                    if (tmp == "..") {
                        if (!v.empty())
                            v.pop_back();
                    }
                    else if (tmp != ".") 
                        v.push_back(tmp);
                    tmp = "";
                }
            } else {
                tmp += path[i];
            }
        }
        
        if (!tmp.empty()) 
            v.push_back(tmp);
        
        string res;
        
        for (string& s: v) {
            cout << s << "\n";
            res += "/" + s;
        }
        
        return res.empty() ? "/" : res;
    }
};