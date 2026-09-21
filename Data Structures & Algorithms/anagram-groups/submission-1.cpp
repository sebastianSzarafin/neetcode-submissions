#include <ranges>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        constexpr std::size_t L = 'z' - 'a' + 1;

        const std::size_t n = strs.size();
        
        std::unordered_map<std::string, std::vector<std::size_t>> map{};

        for (std::size_t s = 0; s < n; ++s) {
            const auto& str = strs[s];

            std::array<std::size_t, L> letters{};
            for (const auto c : str) {
                letters[c - 'a']++;
            }

            std::stringstream hash;
            for (std::size_t i = 0; i < L; ++i) {
                hash << char('a' + i) << letters[i];
            }

            std::string hash_s = hash.str();

            if (!map.contains(hash_s)) {
                map.emplace(hash_s, std::vector<std::size_t>{});
            }
            map.at(hash_s).emplace_back(s);
        }

        std::vector<std::vector<std::string>> result{};

        for (const auto& indices : map | std::views::values) {
            result.emplace_back();
            for (const auto i : indices) {
                result.back().emplace_back(strs[i]);
            }
        }

        return result;
    }
};
