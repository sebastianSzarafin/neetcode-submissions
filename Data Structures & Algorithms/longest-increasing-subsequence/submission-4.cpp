class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        
        if (!n) {
            return 0;
        }
        
        std::vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            std::cout << dp[i] << "\t";
        }
        
        return std::ranges::max(dp);
    }
};
