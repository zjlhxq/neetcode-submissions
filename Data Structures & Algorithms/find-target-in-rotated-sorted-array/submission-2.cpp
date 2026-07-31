class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low= 0, high = nums.size() -1;

        while(low <= high) {
            int mid = low + (high - low) /2;

            if(target == nums[mid]) return mid;
            
            if(nums[low] <= nums[mid]) { // left half is sorted
                if(nums[low] <= target && target < nums[mid]) // target is in left half [low, mid)
                {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else { // right half is sorted
                if (target > nums[mid] && target <= nums[high]) { // seach in space: (mid, high]
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;

    }
};
