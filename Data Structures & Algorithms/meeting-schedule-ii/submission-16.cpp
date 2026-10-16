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
        const int n = intervals.size();
        
        std::ranges::sort(intervals, [](const auto& i1, const auto& i2) {
            if (i1.start == i2.start) {
                return i1.end < i2.end;
            }
            return i1.start < i2.start;
        });

        std::priority_queue<int, std::vector<int>, std::greater<int>> q{};

        for (const auto& i : intervals) {
            if (!q.empty() && q.top() <= i.start) {
                q.pop();
            }
            q.push(i.end);
        }

        return q.size();
    }
};
