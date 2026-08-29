class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        for(auto& interval : intervals) {
            if(result.empty() || result.back()[1] < interval[0]) {
                // no overlap -> start a new interval
                result.push_back(interval);
            } else {
                // overlap -> extends previous interval
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
        
    }
};
