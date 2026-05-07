#include <ranges>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    const auto m = strs.size();

    std::unordered_map<std::string, std::vector<std::size_t>> hash_map;

    for (std::size_t i = 0; i < m; ++i) {
        const auto& s = strs[i];
        const auto n = s.size();
        std::array<int, 26> letters_count{};
        for (std::size_t j = 0; j < n; ++j) {
            letters_count[s[j] - 'a']++;
        }
        std::string hash_s;
        for (std::size_t j = 0; j < 26; ++j) {
            hash_s += std::to_string(letters_count[j]) + std::to_string('a' + j);
        }
        if (!hash_map.contains(hash_s)) {
            hash_map.insert({hash_s, {}});
        }
        hash_map.at(hash_s).emplace_back(i);
    }

    std::vector<std::vector<std::string>> result{};

    for (auto& vec : hash_map | std::views::values) {
        result.emplace_back();
        for (const auto& i : vec) {
            result.back().emplace_back(strs[i]);
        }
    }

    return result;
    }
};
