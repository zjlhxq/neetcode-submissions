class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // for indices
        vector<int> res;
        for(int r = 0; r < nums.size(); r ++) {

            // remove element indices that are out of the window
            while(!dq.empty() && dq.front() <= r - k) {
                dq.pop_front();
            }

            // ensure descreasing elements
            while(!dq.empty() && nums[dq.back()] <= nums[r]) {
                dq.pop_back();
            }

            dq.push_back(r);

            if (r + 1 >= k) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};
