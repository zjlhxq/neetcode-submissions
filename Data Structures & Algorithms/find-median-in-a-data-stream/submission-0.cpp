class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> min_heap; // larger half
    priority_queue<int> max_heap; // small half

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max_heap.push(num);

        if(!min_heap.empty() && !max_heap.empty() && max_heap.top() > min_heap.top()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        if(max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } 

        else if(min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(min_heap.size() > max_heap.size()) {
            return min_heap.top();
        }

        if(min_heap.size() < max_heap.size()) {
            return max_heap.top();
        }

        return (min_heap.top() + max_heap.top()) / 2.0;
    }
};
