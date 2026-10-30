// ##############################################################################################
// ############################ Math observation; O(n) ##########################################
// ##############################################################################################
// class Solution {
// public:
//     int integerBreak(int n) {
        
//         int prod = 0;
        
//         int k = 2;
//         while (k <= n) {
//             int p = n / k;
//             int r = n % k;
//             prod = std::max(prod, (int)std::round(std::pow(p + 1, r) * std::pow(p, k - r)));
//             k++;
//         }

//         return prod;
//     }
// };

// ##############################################################################################
// ################################# DP; O(n^2) #################################################
// ##############################################################################################
class Solution {
public:
    int integerBreak(int n) {
        
        std::vector<std::vector<int>> dp(n + 1, std::vector(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[1][i] = i;
        }
        for (int k = 2; k <= n; ++k) {
            for (int i = k; i <= n; ++i) {
                for (int j = 1; j <= i; ++j) {
                    dp[k][i] = std::max(dp[k][i], dp[k - 1][i - j] * j);
                }
            }
        }
        
        int result = 0;
        for (int k = 2; k <= n; ++k) {
            result = std::max(result, dp[k][n]);
        }

        return result;
    }
};