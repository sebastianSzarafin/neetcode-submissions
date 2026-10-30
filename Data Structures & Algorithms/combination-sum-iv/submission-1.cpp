// ##############################################################################################
// ############################## Recursive; Top down ###########################################
// ##############################################################################################
// class Solution {
// private:
//     int dfs(std::unordered_map<int, int>& dp, const std::vector<int>& nums, const int total) {
//         if (dp.count(total)) {
//             return dp[total];
//         }
//         if (total < 0) {
//             return 0;
//         }

//         int res = 0;
//         for (const int n : nums) {
//             res += dfs(dp, nums, total - n);
//         }
//         dp[total] = res;
//         return res;
//     }

// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         std::unordered_map<int, int> dp{};
//         dp[0] = 1;
//         return dfs(dp, nums, target);
//     }
// };

// ##############################################################################################
// ############################## Iterative; Bottom up ##########################################
// ##############################################################################################
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        const int n = nums.size();

        std::vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int t = 1; t <= target; ++t) {
            for (const int num : nums) {
                if (t - num >= 0) {
                    dp[t] += dp[t - num];
                }
            }
        }

        return dp[target];
    }
};