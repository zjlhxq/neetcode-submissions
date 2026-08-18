class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current_path;
        function<void(int, int)> backtrack = [&](int start, int remaining) {
            if (remaining == 0) {
                result.push_back(current_path);
            }

            if( remaining < 0) {
                return;
            }

            for(int i=start; i<nums.size(); i++) {
                current_path.push_back(nums[i]);
                backtrack(i, remaining - nums[i]);
                current_path.pop_back();
            }

        };

        backtrack(0, target);

        return result;
    }
};
