class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        std::vector<int> d(n + 1);
        d[0] = cost[0];
        d[1] = cost[1];
        for (int i = 2; i < n + 1; ++i) {
            d[i] = (i == n ? 0 : cost[i]) + std::min(d[i - 1], d[i - 2]);
        }
        return d[n];
    }
};
