class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }

        std::unordered_map<char, int> s1_letters{};
        
        for (const auto s : s1) {
            s1_letters[s]++;
        }

        std::unordered_map<char, int> s2_letters{};
        int l = 0, r = s1.size() - 1;

        for (int i = 0; i <= r; ++i) {
            s2_letters[s2[i]]++;
        }

        while (r < s2.size() && s1_letters != s2_letters) {
            s2_letters[s2[++r]]++;
            s2_letters[s2[l]]--;
            if (!s2_letters[s2[l]]) { s2_letters.erase(s2[l]); }
            l++;
        }

        return s1_letters == s2_letters;
    }
};
