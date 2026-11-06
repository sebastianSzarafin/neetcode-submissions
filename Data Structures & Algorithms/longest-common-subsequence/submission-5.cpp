class Solution {
private:
    int dfs(int i, int j, const std::string& text1, const std::string& text2) {

        if (i == text1.size() || j == text2.size()) {
            return 0;
        }

        auto& maxLen = m_dp[i][j];
        if (maxLen.has_value()) {
            return *maxLen;
        }

        maxLen = dfs(i + 1, j, text1, text2); // skip text1[i]

        const auto found = text2.find(text1[i], j);
        if (found != std::string::npos) {
            maxLen = std::max(*maxLen, 1 + dfs(i + 1, found + 1, text1, text2));
        }

        return *maxLen;
    }

    std::vector<std::vector<std::optional<int>>> m_dp;

public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        if (text1.size() > text2.size()) {
            std::swap(text1, text2);
        }

        m_dp = std::vector(text1.size(), std::vector(text2.size(), std::optional<int>{}));

        return dfs(0, 0, text1, text2);
    }
};
