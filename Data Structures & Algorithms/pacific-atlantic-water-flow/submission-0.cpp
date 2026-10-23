class Solution {
private:
    std::set<std::vector<int>> bfs(std::queue<std::vector<int>>& q,
                                             const std::vector<std::vector<int>>& heights) {
        
        const int n = heights.size();
        const int m = heights[0].size();

        std::set<std::vector<int>> result{};

        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

        while (!q.empty()) {
            const auto rc = q.front();
            const int r = rc[0], c = rc[1];
            q.pop();

            if (visited[r][c]) { continue; }

            result.emplace(std::vector{r, c});
            visited[r][c] = true;

            if (r - 1 >= 0 && heights[r][c] <= heights[r - 1][c]) {
                q.push(std::vector{r - 1, c});
            }
            if (r + 1 < n && heights[r][c] <= heights[r + 1][c]) {
                q.push(std::vector{r + 1, c});
            }
            if (c - 1 >= 0 && heights[r][c] <= heights[r][c - 1]) {
                q.push(std::vector{r, c - 1});
            }
            if (c + 1 < m && heights[r][c] <= heights[r][c + 1]) {
                q.push(std::vector{r, c + 1});
            }
        }

        return result;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int n = heights.size();
        if (!n) { return {}; }
        const int m = heights[0].size();

        std::set<std::vector<int>> pacific{};
        {
            std::queue<std::vector<int>> q{};
            for (int i = 0; i < n; ++i) { q.push(std::vector{i, 0}); }
            for (int i = 0; i < m; ++i) { q.push(std::vector{0, i}); }
            pacific = bfs(q, heights);
        }

        std::set<std::vector<int>> atlantic{};
        {
            std::queue<std::vector<int>> q{};
            for (int i = 0; i < n; ++i) { q.push(std::vector{i, m - 1}); }
            for (int i = 0; i < m; ++i) { q.push(std::vector{n - 1, i}); }
            atlantic = bfs(q, heights);
        }

        std::vector<std::vector<int>> result{};
        std::set_intersection(pacific.begin(), pacific.end(),
                              atlantic.begin(), atlantic.end(),
                              std::back_inserter(result));

        return result;
    }
};
