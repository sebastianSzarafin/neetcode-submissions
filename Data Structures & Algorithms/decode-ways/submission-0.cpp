class Solution {
public:

    int dfs(const std::string& s, int i) {
        const int n = s.size();
        if (i >= n) { return 1; }
        int d1 = std::stoi(s.substr(i, 1));
        if (d1 == 0) { return 0; }
        int d2 = i + 1 < n ? std::stoi(s.substr(i, 2)) : 0;
        int c = 0;
        if (1 <= d1 && d1 <= 26) { c += dfs(s, i + 1); }
        if (1 <= d2 && d2 <= 26) { c += dfs(s, i + 2); }
        return c;
    }

    int numDecodings(string s) {
        return dfs(s, 0);
    }
};
