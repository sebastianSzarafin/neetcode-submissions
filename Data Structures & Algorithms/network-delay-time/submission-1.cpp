class Solution {
private:
    using Edge = std::pair<int, int>; // [v, cost]

    std::vector<int> dijkstra(const std::vector<std::vector<Edge>>& edges, int source) {
        const int n = edges.size();
        
        std::vector<int> cost(n, INT_MAX);
        cost[source] = 0;

        auto comp = [&cost](int u, int v) { return cost[u] > cost[v]; };
        std::priority_queue<int, std::vector<int>, decltype(comp)> Q(comp);

        Q.push(source);
        while (!Q.empty()) {
            int u = Q.top();
            Q.pop();

            for (const auto [v, c] : edges[u]) {
                if (cost[u] + c < cost[v]) {
                    cost[v] = cost[u] + c;
                    Q.push(v);
                }
            }
        }

        return cost;
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::vector<std::vector<Edge>> edges(n);

        for (const auto& uvt : times) {
            int u = uvt[0] - 1;
            int v = uvt[1] - 1;
            int t = uvt[2];
            edges[u].emplace_back(v, t);
        }

        const std::vector<int> cost = dijkstra(edges, k - 1);

        for (const auto c : cost) {
            if (c == INT_MAX) { return -1; }
        }

        int time = 0;
        for (const auto c : cost) {
            time = std::max(c, time);
        }

        return time;
    }
};
