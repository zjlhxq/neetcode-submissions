class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(), 
         [](auto& a, auto& b) { return a[0] < b[0]; }
        );

        vector<pair<int, int>> sorted_queries;
        for(int i=0; i<queries.size(); i++) {
            sorted_queries.push_back({queries[i], i});
        }

        sort(sorted_queries.begin(), sorted_queries.end());

        vector<int> result(queries.size(), -1);

        // {size, end}
        priority_queue<tuple<int, int>, vector<tuple<int,int>>, greater<tuple<int, int>>> pq; 
        int i = 0;
        for( auto [query, index] : sorted_queries) {

            // Add intervals that have started
            while(i<intervals.size() && intervals[i][0] <= query ) {
                int start = intervals[i][0];
                int end = intervals[i][1];
                int size = end - start + 1;
                pq.push({size, end});
                ++i;
            }

            // remove expired intervals
            while(!pq.empty() && get<1>(pq.top()) < query) {
                pq.pop();
            }

            // smallest valid interval
            if(!pq.empty()) {
                result[index] = get<0>(pq.top());
            }
        }

        return result;
        
    }
};
