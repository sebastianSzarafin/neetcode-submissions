class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int n = edges.size();

        parent.resize(n + 1);
        std::iota(parent.begin(), parent.end(), 0);
        
        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];

            if (!unite(u, v)) { 
                return e; 
            } 
        }

        return {};
    }

    bool unite(int u, int v) {
        int ru = find(u);
        int rv = find(v);

        if (ru == rv) { return false; }

        parent[ru] = rv;

        return true;
    }

    int find(int u) {
        if (parent[u] == u) {
            return u;
        }

        return find(parent[u]);
    }

private:
    std::vector<int> parent;
};
