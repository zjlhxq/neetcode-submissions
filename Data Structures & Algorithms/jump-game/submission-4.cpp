class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(nums.size(), false);

        dp[n-1] = true;
        for(int i = n - 2; i>=0; i -- ) {
            int furthest = min((int)nums.size() -1, i + nums[i]);

            for(int j = i + 1; j<= furthest; j++) {
                if(dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};