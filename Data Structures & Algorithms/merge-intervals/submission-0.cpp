class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1; i<intervals.size(); ++i) {
            // check if intervals[i-1] overlaps intervals[i]

            if (intervals[i][0] <= end) {
                // overlap
                end = max(end, intervals[i][1]);

            } else {
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        result.push_back({start, end});

        return result;
        
    }
};
