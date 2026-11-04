class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m = obstacleGrid.size();
        if (!m) { return 0; }
        const int n = obstacleGrid[0].size();
        if (!n) { return 0; }

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        dp[0][0] = !obstacleGrid[0][0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) { continue; }
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];      
    }
};
