class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: find interseciton point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // Phase 2: find the cycle
        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
