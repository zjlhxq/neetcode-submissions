class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> result;
        function<void(int, vector<int>&num, vector<int>&)> backtrack = [&](
            int start, 
            vector<int>&nums, 
            vector<int>& current_path) {

            result.push_back(current_path);

            for(int i=start; i<nums.size(); i++) {
                current_path.push_back(nums[i]);
                backtrack(i+1, nums, current_path);
                current_path.pop_back();
            }
        };

        backtrack(0, nums, path);

        return result;
    }
};
