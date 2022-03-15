class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        char c = 'a';
        string res;
        for (int i = 0; i < n; ++i) {
            c = s[i];
            if (c == '(') {
                st.push(i);
            } else if (c == ')') {
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop();
                    // res.push_back(c);
                } else {
                    st.push(i);
                }
            }
        }
        while (!st.empty()) {
            s.erase(st.top(),1);
            st.pop();
        }
        return s;
    }
};