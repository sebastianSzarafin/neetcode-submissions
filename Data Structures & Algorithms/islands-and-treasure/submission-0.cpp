class Solution {
public:
        void islandsAndTreasure(std::vector<std::vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();

        std::vector<std::vector<bool>> visited(n);
        for (auto& row : visited) {
            row.resize(m);
            std::fill(row.begin(), row.end(), false);
        }

        std::queue<std::tuple<int, int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j, -1});
                }
            }
        }

        while (!q.empty()) {
            int s = q.size();
            while (s > 0) {
                auto [i, j, k] = q.front();
                
                q.pop();
                s--;

                if (visited[i][j] || grid[i][j] == -1) { continue; }
                visited[i][j] = true;
                grid[i][j] = k + 1;
                
                if (0 < i) { q.push({i - 1, j, grid[i][j]}); }
                if (i + 1< n) { q.push({i + 1, j, grid[i][j]}); }
                if (0 < j) { q.push({i, j - 1, grid[i][j]}); }
                if (j + 1 < m) { q.push({i, j + 1, grid[i][j]}); }
            }
        }
    }
};
