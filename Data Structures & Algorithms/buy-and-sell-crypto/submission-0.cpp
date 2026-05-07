class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const auto n = prices.size();

        std::size_t start = 0;
        int max_profit = 0;

        for (std::size_t i = 1; i < n; ++i) {
            int profit = prices[i] - prices[start];
            if (profit > max_profit) {
                max_profit = profit;
            }
            if (prices[i] < prices[start]) {
                start = i;
            }
        }

        return max_profit;
    }
};
