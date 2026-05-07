class Solution {
public:
    std::string expand_around_centre(const std::string& s, int l, int r) {
        const int n = s.size();
    
        while (0 <= l && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }

    string longestPalindrome(string s) {
        const int n = s.size();

        std::string sol = "";
        for (int i = 0; i < n; ++i) {
            std::string s1 = expand_around_centre(s, i, i);
            std::string s2 = expand_around_centre(s, i, i + 1);
            if (s1.size() < s2.size()) { std::swap(s1, s2); }
            if (s1.size() > sol.size()) { sol = s1; }
        }
        return sol;
    }
};
