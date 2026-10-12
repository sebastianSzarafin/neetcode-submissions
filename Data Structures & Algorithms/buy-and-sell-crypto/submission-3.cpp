class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();

        int l = 0;
        int r = 1;

        int res = 0;

        while (r < n) {
            res = std::max(res, prices[r] - prices[l]);
            if (prices[l] > prices[r]) {
                l = r;
            }
            r++;
        }

        return res;
    }
};
