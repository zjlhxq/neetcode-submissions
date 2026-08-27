class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](pair<int, int> & a, pair<int, int> & b) {
            return (a.first * a.first + a.second*a.second) < (b.first*b.first + b.second*b.second);
        };
        
        // max heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq;

        for( auto &point: points) {
            pq.push({point[0], point[1]});
            if(k -- <= 0 ) {
                pq.pop();
            }
        }

        vector<vector<int>> result;
        while(!pq.empty()) {
            auto &pt = pq.top();
            result.push_back({pt.first, pt.second});
            pq.pop();
        }

        return result;
    }
};
