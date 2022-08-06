class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openParen;
        stack<int> star;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '(') {
                openParen.push(i);
            } else if (c == '*') {
                star.push(i);
            } else {
                if (openParen.empty() && star.empty()) return false;
                if (!openParen.empty()) {
                    openParen.pop();
                } else {
                    star.pop();
                }
            }
        }
        while (!openParen.empty() && !star.empty()) {
            if (openParen.top() > star.top()) {
                return false;
            }
            openParen.pop();
            star.pop();
        }
        return openParen.empty();
    }
};