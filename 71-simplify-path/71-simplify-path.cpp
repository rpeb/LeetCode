class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> v;
        string tmp;
        stack<string> st;
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
            tmp="";
        
        for (auto x: v) {
            cout << "x = " << x << "\n";
            if (x == "." || (x == ".." && st.empty())) {
                continue;
            } else if (x == "..") {
                st.pop();
            } else {
                st.push(x);
            }
        }
                cout << "stack size = " << st.size() << "\n";

        while (!st.empty()) {
            tmp = st.top() + "/" + tmp;
                    cout << "tmp = " << tmp << "\n";

            st.pop();
        }
        tmp = "/" + tmp;
        cout << "tmp = " << tmp << "\n";
        return (tmp=="/") ? "/" : tmp.substr(0,tmp.size()-1);
    }
};