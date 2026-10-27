class Solution {
public:
    int countSubstrings(std::string s) {
        const int n = s.size();

        std::vector<std::vector<bool>> dp(n, std::vector(n, false));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            if (i + 1 < n) {
                dp[i][i + 1] = s[i] == s[i + 1];
            }
        }
        for (int j = 2; j < n; ++j) {
            for (int i = 0; i < j - 1; ++i) {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            }
        }

        int count = 0;

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i <= j; ++i) {
                count += static_cast<int>(dp[i][j]);
            }
        }

        return count;
    }
};