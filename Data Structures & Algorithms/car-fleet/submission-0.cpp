class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        for(int i=0; i<n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end());
        int fleets = 0;
        double max_time_seen = 0.0;
        for( int i = n - 1; i>=0; i--) {
            auto[pos, spd] = cars[i];
            double current_car_time = (double)(target-pos) / spd;
            if(current_car_time > max_time_seen ) {
                fleets ++;
                max_time_seen = current_car_time;
            }
        }

        return fleets;
    }
};
