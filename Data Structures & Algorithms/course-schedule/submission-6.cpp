class Solution {
private:
    // 0 = unvisited, 1 = visiting, 2 = processed
    bool containsCycle(
        int u,
        const std::vector<std::vector<int>>& graph,
        std::vector<int>& state
    ) {
        if (state[u] == 1) {
            return true;  // Back edge: cycle detected
        }

        if (state[u] == 2) {
            return false; // Already checked; no cycle found
        }

        state[u] = 1;

        for (const int v : graph[u]) {
            if (containsCycle(v, graph, state)) {
                return true;
            }
        }

        state[u] = 2; // All descendants checked successfully
        return false;
    }

public:
    bool canFinish(
        int numCourses,
        std::vector<std::vector<int>>& prerequisites
    ) {
        std::vector<std::vector<int>> graph(numCourses);

        for (const auto& edge : prerequisites) {
            graph[edge[1]].emplace_back(edge[0]);
        }

        std::vector<int> state(numCourses, 0);

        for (int u = 0; u < numCourses; ++u) {
            if (state[u] == 0 &&
                containsCycle(u, graph, state)) {
                return false;
            }
        }

        return true;
    }
};