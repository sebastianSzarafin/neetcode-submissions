class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const auto n = intervals.size();
        std::ranges::sort(intervals, [](const auto& l, const auto& r) { return l[0] < r[0]; });
        std::vector<std::vector<int>> result;
        int i = 0;
        while (i < n) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            while (i + 1 < n && end >= intervals[i + 1][0]) {
                end = std::max(end, intervals[i + 1][1]);
                i++;
            }
            i++;
            result.emplace_back(std::vector{start, end});
        }
        return result;
    }
};
