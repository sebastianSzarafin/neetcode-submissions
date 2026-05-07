class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();

        std::sort(intervals.begin(), intervals.end(), 
            [](const auto& l, const auto& r) 
            {
                return l[0] == r[0] ? l[1] < r[1] : l[0] < r[0];
            });

        int overlapping = 0;

        int i = 0;
        int curr_end = intervals[i][1];
        while (i < n) {
            int j = i + 1;
            while (j < n && curr_end > intervals[j][0]) {
                curr_end = std::min(curr_end, intervals[j][1]);
                j++;
                overlapping++;
            }
            i = j;
            if (i < n) { curr_end = intervals[i][1]; }
        }

        return overlapping;
    }
};
