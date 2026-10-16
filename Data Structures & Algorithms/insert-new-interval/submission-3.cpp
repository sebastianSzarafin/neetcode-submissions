class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        const int n = intervals.size();

        std::vector<std::vector<int>> result{};

        int i = 0;
        
        while(i < n && intervals[i][1] < newInterval[0]) {
            result.emplace_back(intervals[i]);
            i++;
        }
        int begin = i < n ? std::min(intervals[i][0], newInterval[0]) : newInterval[0];
        int end = newInterval[1];

        while (i < n && intervals[i][0] <= newInterval[1]) {
            end = std::max(intervals[i][1], newInterval[1]);
            i++;
        }

        result.emplace_back(std::vector{begin, end});

        while(i < n) {
            result.emplace_back(intervals[i]);
            i++;
        }

        return result;
    }
};
