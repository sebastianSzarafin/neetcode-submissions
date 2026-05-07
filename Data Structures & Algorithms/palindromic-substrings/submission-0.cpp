class Solution {
public:
    int expand_around_centre(const std::string& s, int l, int r) {
        const int n = s.size();
    
        int count = 0;
        while (0 <= l && r < n && s[l] == s[r]) {
            l--;
            r++;
            count++;
        }
        return count;
    }

    int countSubstrings(string s) {
        const int n = s.size();

        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += expand_around_centre(s, i, i);
            count += expand_around_centre(s, i, i + 1);
        }
        return count;
    }
};
