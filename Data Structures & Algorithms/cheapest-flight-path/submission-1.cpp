class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        std::vector<std::vector<std::pair<int, int>>> graph(n);
        for (const auto& f : flights) {
            const int u = f[0];
            const int v = f[1];
            const int c = f[2];
            graph[u].emplace_back(v, c);
        }

        std::vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        for (int i = 0; i <= k; ++i) {
            std::vector<int> tmp = cost;
            for (int u = 0; u < n; ++u) {
                for (const auto& [v, c] : graph[u]) {
                    if (cost[u] == INT_MAX) { continue; }
                    int alt = cost[u] + c;
                    if (alt < cost[v]) {
                        tmp[v] = alt;
                    }
                }
            }
            cost = tmp;
        }

        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};
