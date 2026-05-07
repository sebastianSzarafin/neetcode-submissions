#include <ranges>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const auto n = s2.size();
        
        std::vector<int> s1_letters('z' - 'a', 0);

        for (const char c : s1) {
            s1_letters[c - 'a']++;
        }

        int left = 0;
        std::vector<int> s2_letters('z' - 'a', 0);
        
        for (int right = 0; right < n; ++right) {

            const char c = s2[right];
            const int c_idx = c - 'a';

            if (s1_letters[c_idx]) {
                s2_letters[c_idx]++;
            }
            else {
                std::ranges::fill(s2_letters, 0);
                left = right + 1;
            }

            while (s2_letters[s2[left] - 'a'] > s1_letters[c_idx]) {
                s2_letters[s2[left] - 'a']--;
                left++;
            }
            
            if (s1_letters == s2_letters) {
                return true;
            }
        }

        return false;
    }
};
