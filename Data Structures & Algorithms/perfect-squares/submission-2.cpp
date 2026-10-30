class Solution {
public:
    int numSquares(int n) {
        std::vector<int> ps{};
        int i = 1;
        while (i * i <= n) {
            ps.emplace_back(i * i);
            i++;
        }

        std::vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (const int s : ps) {
                if (i - s >= 0 && dp[i] > dp[i - s] + 1) {
                    dp[i] = dp[i - s] + 1;
                }
            }
        }

        return dp[n];
    }
};