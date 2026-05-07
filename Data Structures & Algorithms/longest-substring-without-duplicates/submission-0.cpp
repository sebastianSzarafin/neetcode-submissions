class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    const auto n = s.size();

    std::map<char, std::size_t> char_map; // {letter, last pos}
    int result = 0;

    std::size_t i = 0;
    std::size_t j = 0;
    while (j < n) {
        while(j < n && !char_map.contains(s[j])) {
            char_map.emplace(s[j], j);
            ++j;
        }
        result = std::max(result, static_cast<int>(j - i));
        auto pi = i;
        i = char_map[s[j]] + 1;
        while (pi < i) {
            char_map.erase(s[pi]);
            ++pi;
        }
    }

    return result;
    }
};
