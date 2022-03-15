class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        // keep the indices to be removed from s
        stack<int> st;
        char c = 'a';
        for (int i = 0; i < n; ++i) {
            c = s[i];
            // index of open paren is stored in stack
            if (c == '(') {
                st.push(i);
            } else if (c == ')') {
                // to handle cases like "))(("
                // where closing paren should only pop opening paren
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop();
                } else {
                    st.push(i);
                }
            }
        }
        while (!st.empty()) {
            // remove redundant parens from original string
            s.erase(st.top(),1);
            st.pop();
        }
        return s;
    }
};