class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto greater = [](int a, int b) {
            return a > b;
        };

        // min heap
        priority_queue<int, vector<int>, decltype(greater)> pq;

        for( int num : nums) {
            pq.push(num);
            if(pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};
