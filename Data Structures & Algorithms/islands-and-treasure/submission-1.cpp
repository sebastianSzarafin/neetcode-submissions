class Solution {
private:
    static constexpr int inf = INT_MAX;

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int n = grid.size();
        if (!n) { return; }
        const int m = grid[0].size();

        std::queue<std::tuple<int, int, int>> q{};
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    q.push(std::tuple{i, j, 0});
                }
            }
        }

        while (!q.empty()) {
            const auto [i, j, d] = q.front();
            q.pop();

            if (i - 1 >= 0 && grid[i - 1][j] == inf) {
                grid[i - 1][j] = d + 1;
                q.push(std::tuple{i - 1, j, d + 1});
            }
            if (i + 1 < n && grid[i + 1][j] == inf) {
                grid[i + 1][j] = d + 1;
                q.push(std::tuple{i + 1, j, d + 1});
            }
            if (j - 1 >= 0 && grid[i][j - 1] == inf) {
                grid[i][j - 1] = d + 1;
                q.push(std::tuple{i, j - 1, d + 1});
            }
            if (j + 1 < m && grid[i][j + 1] == inf) {
                grid[i][j + 1] = d + 1;
                q.push(std::tuple{i, j + 1, d + 1});
            }
        }
    }
};
