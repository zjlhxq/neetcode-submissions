class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);

        function<bool(int)> canReach = [&](int i) {
            // Base case: already at or beyond the destination.
            if (i >= nums.size() - 1)
                return true;

            // Already solved.
            if (memo[i] != -1)
                return memo[i] == 1;

            int furthest = min(
                (int)nums.size() - 1,
                i + nums[i]
            );

            // Try every possible next position.
            for (int j = i + 1; j <= furthest; j++) {
                if (canReach(j)) {
                    memo[i] = 1;
                    return true;
                }
            }

            memo[i] = 0;
            return false;
        };

        return canReach(0);
    }
};