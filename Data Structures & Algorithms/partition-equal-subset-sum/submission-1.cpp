class Solution {
private:
    // bool dfs(std::vector<std::vector<int>>& dp,
    //          const std::vector<int>& nums,
    //          const int i,
    //          const int target) {
        
    //     const int n = dp.size();
    //     const int t = dp[0].size();

    //     if (i == n) {
    //         return std::ranges::any_of(dp[i], [target](const int r) { return r == target; });
    //     }

    //     for (int j = 0; j < t; ++j) {
    //         dp[i][j] = dp[i - 1][j] + nums[i];

    //     }
    // }


public:
    bool canPartition(vector<int>& nums) {
        const int n = nums.size();
        if (!n) { return false; }

        int t = std::accumulate(nums.begin(), nums.end(), 0);
        if (t % 2 == 1) { return false; }
        t /= 2;

        std::vector<std::vector<bool>> dp(n, std::vector(t + 1, false));
        dp[0][0] = true;
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < t; ++j) {
                if (!dp[i - 1][j]) { continue; }
                dp[i][j] = true;
                if (j + nums[i] <= t) {
                    dp[i][j + nums[i]] = true;
                }
            }
        }

        return dp[n - 1][t];
    }
};
