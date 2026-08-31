class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int prev_end = INT_MIN;
        int removed = 0;
        for(auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            if(start >= prev_end) {
                prev_end = end;    
            } else {
                removed ++;
                prev_end = min(prev_end, end);
            }
        }

        return removed;
    }
};
