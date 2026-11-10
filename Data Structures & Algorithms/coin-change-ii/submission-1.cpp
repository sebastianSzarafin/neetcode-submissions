class Solution {
private:
    int dfs(const std::vector<int>& coins, const int c, const int target) {

        if (target == 0) {
            return 1;
        }

        if (c == coins.size() || target < 0) {
            return 0;
        }

        int& combinations = m_dp[target][c];
        if (combinations != -1) {
            return combinations;
        }

        combinations = 0;
        combinations += dfs(coins, c, target - coins[c]);
        combinations += dfs(coins, c + 1, target);
        return combinations;
    }

    std::vector<std::vector<int>> m_dp;

public:
    int change(int amount, std::vector<int>& coins) {

        m_dp = std::vector(amount + 1, std::vector(coins.size(), -1));
        // m_dp[0] = std::vector(coins.size(), 1);

        return dfs(coins, 0, amount);
    }
};