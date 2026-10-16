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
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        std::ranges::sort(intervals, [](const auto& i1, const auto& i2) {
            if (i1.start == i2.start) {
                return i1.end < i2.end;
            }
            return i1.start < i2.start;
        });

        for (int i = 0; i + 1 < intervals.size(); ++i) {
            if (intervals[i].end > intervals[i + 1].start) {
                return false;
            }
        }
        return true;
    }
};
