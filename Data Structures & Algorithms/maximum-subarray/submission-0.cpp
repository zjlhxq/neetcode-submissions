class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int subSum = nums[0];
        int maxSum = nums[0];
        for(int i=1; i<nums.size(); i++) {
            subSum = max(nums[i], subSum + nums[i]);
            maxSum = max(maxSum, subSum);
        }

        return maxSum;
    }
};
