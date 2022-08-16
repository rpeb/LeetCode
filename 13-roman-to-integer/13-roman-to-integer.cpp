class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int res = 0;
        unordered_map<string,int> values = {
            {"I",1},
            {"V",5},
            {"X",10},
            {"IV",4},
            {"IX",9},
            {"XL",40},
            {"L",50},
            {"XC",90},
            {"C",100},
            {"D",500},
            {"M",1000},
            {"CD",400},
            {"CM",900}
        };
        int i = 0;
        
        while (i < n) {
            string tmp = s.substr(i, 2);
            if (values.find(tmp) != values.end()) {
                res += values[tmp];
                i += 2;
            } else {
                // string(1,'x') -> "x" .. used to convert a char to string
                res += values[string(1,s[i])];
                i++;
            }
        }
        return res;
    }
};