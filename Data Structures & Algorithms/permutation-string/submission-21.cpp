#include <ranges>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const auto n1 = s1.size();
        const auto n2 = s2.size();
        
        std::vector<int> s1_letters('z' - 'a', 0);

        for (const char c : s1) {
            s1_letters[c - 'a']++;
        }

        std::vector<int> win_letters('z' - 'a', 0);

        for (int right = 0; right < n1; ++right) {
            win_letters[s2[right] - 'a']++;
        }

        int left = 0;
        for (int right = n1; right < n2; ++right) {
            if (s1_letters == win_letters) { return true; }
            win_letters[s2[right] - 'a']++;
            win_letters[s2[left] - 'a']--;
            ++left;
        }

        return s1_letters == win_letters;
    }
};
