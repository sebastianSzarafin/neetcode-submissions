class Solution {
private:
    int dfs(const std::vector<int>& prices, const int i, const bool haveCoin) {
        if (i >= prices.size()) {
            return 0;
        }

        int& result = m_dp[i][haveCoin];
        if (result != -1) {
            return result;
        }

        int hold = dfs(prices, i + 1, haveCoin);

        if (haveCoin) {
            int sell = dfs(prices, i + 2, false) + prices[i];
            result = std::max(hold, sell);
        }
        else {
            int buy = dfs(prices, i + 1, true) - prices[i];
            result = std::max(hold, buy);
        }

        return result;
    }

    std::vector<std::vector<int>> m_dp;

public:
    int maxProfit(vector<int>& prices) {
        m_dp = std::vector(prices.size(), std::vector(2, -1));
        return dfs(prices, 0, false);
    }
};
