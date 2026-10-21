class Solution {
private:
    struct Vec {
        int x;
        int y;

        int norm() const { return x * x + y * y; }

        bool operator<(const Vec& other) const {
            return this->norm() < other.norm();
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<Vec> q{};

        for (const auto& p : points) {
            q.push(Vec(p[0], p[1]));
            if (q.size() > k) {
                q.pop();
            }
        }

        std::vector<std::vector<int>> result{};

        while (!q.empty()) {
            Vec p = q.top();
            result.emplace_back(std::vector{p.x, p.y});
            q.pop();
        }

        return result;
    }
};
