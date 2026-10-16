class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int n = intervals.size();

        std::ranges::sort(intervals, [](const auto& i1, const auto& i2) {
            if (i1[0] == i2[0]) {
                return i1[1] < i2[1];
            }
            return i1[0] < i2[0];
        });

        std::vector<std::vector<int>> result{};

        for (int i = 0; i < n; ++i) {
            int begin = intervals[i][0];
            int end = intervals[i][1];
            int j = i;
            
            while (j + 1 < n && end >= intervals[j + 1][0]) {
                end = std::max(end, intervals[j + 1][1]);
                j++;
            }
            i = j;
            
            result.emplace_back(std::vector{begin, end});
        }

        return result;
    }
};
