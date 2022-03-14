class Solution {
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