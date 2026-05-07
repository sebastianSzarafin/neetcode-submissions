class Solution {
private:
    struct Point {
        int x;
        int y;
    };
    
    struct Edge {
        int u;
        int v;
        int cost;
    };

    class DSU {
    public:
        DSU(int n) {
            parent.resize(n);
            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        int find(int i) {
            if (i == parent[i]) {
                return i;
            }
            return find(parent[i]);
        }

        bool unite(int u, int v) {
            int rootu = find(u);
            int rootv = find(v);

            if (rootu != rootv) {
                parent[rootu] = rootv;
                return true;
            }
            return false;
        }
    
    private:
        std::vector<int> parent;
        // std::vector<int> rank;
    };

    int manhatan(const Point& p1, const Point& p2) {
        return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        
        std::vector<Edge> edges;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                Point pi(points[i][0], points[i][1]);
                Point pj(points[j][0], points[j][1]);
                edges.emplace_back(i, j, manhatan(pi, pj));
            }
        }
        std::sort(edges.begin(), edges.end(), [](const auto& e1, const auto& e2) { return e1.cost < e2.cost; });

        int min_cost = 0;

        DSU dsu(n);
        for (const auto& e : edges) {
            if(dsu.unite(e.u, e.v)) {
                min_cost += e.cost;
            }
        }

        return min_cost;
    }
};
