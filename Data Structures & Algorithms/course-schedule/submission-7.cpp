class Solution {
private:
    bool containsCycle(std::vector<int>& states, const int u, const std::vector<std::vector<int>>& graph) {
        if (states[u] == 1) {
            return true;
        }

        if (states[u] == 2) {
            return false;
        }

        states[u] = 1;

        for (const int v : graph[u]) {
            if (containsCycle(states, v, graph)) {
                return true;
            }
        }

        states[u] = 2;
        return false;
    }

public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph(numCourses);
        for (const auto& edge : prerequisites) {
            graph[edge[1]].emplace_back(edge[0]);
        }

        std::vector<int> states(numCourses, 0);
        // 0 = unvisited
        // 1 = visiting
        // 2 = processed

        for (int u = 0; u < numCourses; ++u) {
            if (states[u] == 0 && containsCycle(states, u, graph)) {
                return false;
                }
        }

        return true;
    }
};