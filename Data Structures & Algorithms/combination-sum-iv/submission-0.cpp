class Solution {
private:
    int dfs(std::unordered_map<int, int>& dp, const std::vector<int>& nums, const int total) {
        if (dp.count(total)) {
            return dp[total];
        }
        if (total < 0) {
            return 0;
        }

        int res = 0;
        for (const int n : nums) {
            res += dfs(dp, nums, total - n);
        }
        dp[total] = res;
        return res;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        std::unordered_map<int, int> dp{};
        dp[0] = 1;
        return dfs(dp, nums, target);
    }
};