class Solution {
public:
    int characterReplacement(string s, int k) {
        constexpr int L = 'Z' - 'A' + 1;

        if (s.empty()) {
            return 0;
        }

        const int n = s.size();

        std::vector<int> win_letters(L, 0);
        int l = 0, r = 1;
        char chosen = s[l];
        win_letters[chosen - 'A']++;
        int result = 1;

        while (r < n) {

            win_letters[s[r] - 'A']++;
            if (win_letters[s[r] - 'A'] > win_letters[chosen - 'A']) {
                chosen = s[r];
            }

            if (s[r] != chosen) {
                while ((r - l + 1) - win_letters[chosen - 'A'] > k) {
                    win_letters[s[l] - 'A']--;
                    l++;
                    chosen = std::distance(win_letters.begin(),
                                           std::ranges::max_element(win_letters)) + 'A';
                }
            }
            
            result = std::max(result, r - l + 1);
            r++;
        }

        return result;
    }
};
