/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        const auto n = intervals.size();

        std::vector<int> start;
        std::ranges::transform(intervals, std::back_inserter(start), [](const auto& i) { return i.start; });
        std::ranges::sort(start);
        
        std::vector<int> end;
        std::ranges::transform(intervals, std::back_inserter(end), [](const auto& i) { return i.end; });
        std::ranges::sort(end);

        int s = 0;
        int e = 0;
        int count = 0;
        int max_count = 0;
        
        while (s < n && e < n) {

            if (start[s] < end[e]) {
                s++;
                count++;
            }

            max_count = std::max(max_count, count);

            if (end[e] <= start[s]) {
                e++;
                count--;
            }
        }

        return max_count;
    }
};
