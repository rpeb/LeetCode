class Solution {
    vector<list<pair<int,int>>> map;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        map.resize(10);
        string encoded;
        int n = longUrl.size();
        for (int i = 0; i < n; ++i) {
            char x = longUrl[i];
            int hash = ((x - 'a') + 97) % 10;
            encoded += to_string(hash);
            map[hash].push_back({i,x});
        }
        return encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int n = shortUrl.size();
        string decoded;
        for (int i = 0; i < n; ++i) {
            int idx = shortUrl[i] - '0';
            decoded += map[idx].front().second;
            map[idx].pop_front();
        }
        return decoded;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));