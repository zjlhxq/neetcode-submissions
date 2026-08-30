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
        // sort by start time
        sort(intervals.begin(), intervals.end(), [](auto& a, auto&b){ return a.start < b.start; });

        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (auto& interval : intervals) {
            if(!min_heap.empty() && min_heap.top() <= interval.start) {
                min_heap.pop();
            }

            min_heap.push(interval.end);
        }

        return min_heap.size();
    }
};
