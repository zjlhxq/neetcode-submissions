class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        } );

        int prev_end = INT_MIN;
        int kept = 0;
        for(auto& interval : intervals) {
            if(interval[0] >= prev_end) {
                prev_end = interval[1];
                kept ++;    
            } 
        }

        return intervals.size() - kept;
    }
};
