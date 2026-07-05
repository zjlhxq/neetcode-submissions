#include <queue>

using namespace std;
class KthLargest {

private: 
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int kth_largest;
public:
    KthLargest(int k, vector<int>& nums) : kth_largest(k) {
        for( auto& num: nums) {
            min_heap.push(num);
            if(min_heap.size() > k) {
                min_heap.pop();
            }
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        if(min_heap.size() > kth_largest) {
            min_heap.pop();
        }

        return min_heap.top();
    }
};
