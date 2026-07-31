class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1, high = *std::max_element(piles.begin(), piles.end());
        int result = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (can_finish(piles, h, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }

private:
    bool can_finish(vector<int> & piles, int h, int k) {
        long long total_hours = 0;
        for(auto pile: piles) {
            total_hours += (pile + k - 1) / k;
            if (total_hours > h) return false;
        }

        return total_hours <= h;
    }    
};
