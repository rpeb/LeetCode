class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int l = 0;
        int n = pushed.size();
        int n2 = popped.size();
        for (int i = 0; i < n; ++i) {
            st.push(pushed[i]);
            while (!st.empty() && l < n2 && st.top() == popped[l]) {
                st.pop();
                l++;
            }
        }
        return l == n2;
    }
};