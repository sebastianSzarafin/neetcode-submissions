class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }
        
        std::vector<bool> visited(n, false);
        std::vector<int> parent(n, -1);
        std::stack<int> s;
        visited[0] = true;
        s.push(0);

        while (!s.empty()) {
            int v = s.top();
            s.pop();
            
            for (const int u : g[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    parent[u] = v;
                    s.push(u);
                }
                else if (u != parent[v]) {
                    return false;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }
};
