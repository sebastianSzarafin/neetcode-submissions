#include <ranges>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char, int> count{};
        for (const auto t : tasks) {
            if (!count.contains(t)) {
                count.emplace(std::pair{t, 0});
            }
            count[t]++;
        }

        std::priority_queue<int> pq{};

        for (const auto c : count | std::ranges::views::values) {
            pq.push(c);
        }

        std::queue<std::pair<int, int>> q{};

        int cycle = 0;

        while (!pq.empty() || !q.empty()) {
            cycle++;
            
            if (!pq.empty()) {
                int remaining_count = pq.top();
                remaining_count -= 1;
                if (remaining_count > 0) {
                    q.push(std::pair{remaining_count, cycle + n});
                }
                pq.pop();
            }
            while (!q.empty() && q.front().second <= cycle) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return cycle;
    }
};
