class Solution {
    bool isNum(string s) {
        return !(s[0] == 'C' || s[0] == 'D' || s[0] == '+');
    }
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for (string op: ops) {
            if (isNum(op)) {
                st.push(stoi(op));
            } else if (op == "C") {
                st.pop();
            } else if (op == "D") {
                int top = st.top();
                st.push(top * 2);
            } else {
                int top = st.top();
                st.pop();
                int belowTop = st.top();
                // st.push(belowTop);
                st.push(top);
                st.push(top + belowTop);
            }
        }
        int res = 0;
        while (!st.empty()) {
            int top = st.top();
            res += top;
            st.pop();
        }
        return res;
    }
};