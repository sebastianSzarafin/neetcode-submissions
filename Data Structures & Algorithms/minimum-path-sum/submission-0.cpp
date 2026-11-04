class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        if (!m) { return 0; }
        const int n = grid[0].size();
        if (!n) { return 0; }

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!i && !j) { continue; }
                
                dp[i][j] = grid[i][j];
                int p1 = i > 0 ? dp[i - 1][j] : INT_MAX;
                int p2 = j > 0 ? dp[i][j - 1] : INT_MAX;
                
                dp[i][j] += std::min(p1, p2);
            }
        }

        return dp[m - 1][n - 1];   
    }
};