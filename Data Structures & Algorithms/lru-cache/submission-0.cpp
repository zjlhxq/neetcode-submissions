class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {
        
    }
    
    int get(int key) {
        if (!cache_map.contains(key)) {
            return -1;
        }

        auto it = cache_map[key];
        int val = it->second;
        cache_list.splice(cache_list.begin(), cache_list, it);
        return val;
    }
    
    void put(int key, int value) {
        if(cache_map.contains(key)) {
            auto map_it = cache_map[key];
            map_it->second = value;

            cache_list.splice(cache_list.begin(), cache_list, map_it);
            return;
        }

        if(cache_map.size() == capacity) {
            int least_used_key = cache_list.back().first;
            cache_map.erase(least_used_key);
            cache_list.pop_back();
        }

        cache_list.push_front({key, value});
        cache_map[key] = cache_list.begin();
    }
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> cache_map;
    list<pair<int, int>> cache_list;
};
