class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();

        int max_profit = 0;

        int l = 0;
        while (l < n) {
            int r = l + 1;
            int profit = 0;
            while (r < n && profit < prices[r] - prices[l]) {
                profit = prices[r] - prices[l];
                r++;
            }
            max_profit += profit;
            l = r;
        }

        return max_profit;
    }
};