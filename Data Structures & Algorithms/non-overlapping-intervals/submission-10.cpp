class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();

        if (!n) {
            return 0;
        }

        std::ranges::sort(intervals, [](const auto& i1, const auto& i2) {
            if (i1[0] == i2[0]) {
                return i1[1] < i2[1];
            }
            return i1[0] < i2[0];
        });

        std::vector<std::vector<int>> kept{};
        kept.emplace_back(intervals.front());

        for (int i = 1; i < n; ++i) {
            if (kept.back()[1] <= intervals[i][0]) {
                kept.emplace_back(intervals[i]);
            }
            else {
                kept.back()[1] = std::min(kept.back()[1], intervals[i][1]);
            }
        }

        return intervals.size() - kept.size();
    }
};
