class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int n = grid[0].size();
        const int m = grid.size();

        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                }
            }
        }

        int result = 0;

        std::vector<std::vector<bool>> visited(m, std::vector(n, false));
        while (!q.empty()) {
            int qs = q.size();

            bool c = false;
            while (qs--) {
                const auto [i, j] = q.front();
                q.pop();

                if (visited[i][j]) {
                    continue;
                }

                if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = 2;
                    q.emplace(i - 1, j);
                    c = true;
                }
                if (i + 1 <= m - 1 && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = 2;
                    q.emplace(i + 1, j);
                    c = true;
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 2;
                    q.emplace(i, j - 1);
                    c = true;
                }
                if (j + 1 <= n - 1 && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 2;
                    q.emplace(i, j + 1);
                    c = true;
                }

                visited[i][j] = true;
            }

            if (c) {
                result++;
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return result;
    }
};
