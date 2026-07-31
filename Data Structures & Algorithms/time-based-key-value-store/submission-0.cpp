class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> backing_map;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        backing_map[key].emplace_back(move(value), timestamp);
    }
    
    string get(string key, int timestamp) {
        if(!backing_map.contains(key)) return "";

        for(auto[key, value] : backing_map) {
            cout << "key: " << key << " value: " << value.size() << endl;
        }

        auto val = backing_map[key];

        // Run binary search
        int l = 0, r= val.size() - 1;
        string result = "";
        while(l <= r ) {
            int mid = l + (r - l) / 2;
            int mid_val = val[mid].second;
            if (timestamp >= mid_val) {
                // don't break
                l = mid + 1;
                result = val[mid].first;
            } else if (timestamp < mid_val) {
                r = mid - 1;
            }
        }

        return result;

    }
};
