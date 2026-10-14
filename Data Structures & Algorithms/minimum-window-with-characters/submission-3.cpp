class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> s_letters{};
        std::unordered_map<char, int> t_letters{};

        for (const char c : s) {
            s_letters[c]++;
        }

        for (const char c : t) {
            t_letters[c]++;
            if (!s_letters.contains(c) || s_letters[c] < t_letters[c]) {
                return "";
            }
        }

        int l_res = -1;
        int r_res = -1;
        int len_res = INT_MAX;

        std::unordered_map<char, int> window{};
        int have = 0;
        int need = t_letters.size();
        int l = 0;

        for (int r = 0; r < s.size(); ++r) {
            const char c = s[r];
            window[c]++;

            if (t_letters.contains(c) && window[c] == t_letters[c]) {
                have++;
            }

            while (have == need) {
                if (int len = r - l + 1; len < len_res) {
                    l_res = l;
                    r_res = r;
                    len_res = len;
                }

                window[s[l]]--;
                if (t_letters.contains(s[l]) && window[s[l]] < t_letters[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return s.substr(l_res, len_res);
    }
};
