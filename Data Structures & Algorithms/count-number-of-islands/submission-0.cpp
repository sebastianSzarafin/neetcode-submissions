class Solution {
public:
int numIslands(std::vector<std::vector<char>>& grid) {
    using Vertex = std::pair<int, int>;

    const auto n = grid.size();
    const auto m = grid[0].size();

    std::set<Vertex> visited;
    int islands = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visited.contains({i, j})) { continue; }
            if (grid[i][j] == '0') { continue; }

            std::stack<Vertex> s;
            s.push({i, j});
            while (!s.empty()) {
                Vertex v = s.top();
                auto [vi, vj] = v;

                s.pop();

                if (visited.contains(v)) { continue; }
                visited.insert(v);

                if (grid[vi][vj] == '0') { continue; }

                if (0 <= vi - 1) { s.push({vi - 1, vj}); }
                if (vi + 1 <= n - 1) { s.push({vi + 1, vj}); }
                if (0 <= vj - 1) { s.push({vi, vj - 1}); }
                if (vj + 1 <= m - 1) { s.push({vi, vj + 1}); }
            }

            islands++;
        }
    }

    return islands;
}
};
