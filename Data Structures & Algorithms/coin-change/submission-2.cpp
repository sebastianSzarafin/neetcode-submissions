class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, INT_MAX / 2);
        dp[0] = 0;
        for (int i = 0; i < amount + 1; ++i) {
            for (const int c : coins) {
                if (i - c < 0) { continue; }
                dp[i] = std::min(dp[i], 1 + dp[i - c]);
            }
        }
        return dp[amount] == INT_MAX / 2 ? -1 : dp[amount];
    }
};
