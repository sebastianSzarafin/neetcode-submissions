class Solution {
public:
    int jump(std::vector<int>& nums) {
        const int n = nums.size();
        if (!n) { return 0; }

        std::vector<int> dp(n);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = 1 + std::min(dp[i + 1], dp[std::min(i + nums[i], n - 1)]);
        }

        return dp[0];
    }
};