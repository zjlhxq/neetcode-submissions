class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int num: nums) {
            count[num] ++;
        }

        auto comp = [&](int a, int b) {
            return count[a] > count[b];
        };

        priority_queue<int, vector<int>, decltype(comp)> min_heap(comp);

        for(auto &[num, freq]: count) {
            min_heap.push(num);
            if(min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> result;
        while(!min_heap.empty()) {
            result.push_back(min_heap.top());
            min_heap.pop();
        }

        return result;
    }
};
