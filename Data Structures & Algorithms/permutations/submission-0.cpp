class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        function<void()> backtrack = [&]( ){
            if(path.size() == nums.size()) {
                result.push_back(path);
                return;
            }

            for(int i=0; i<nums.size(); i++) {
                if(used[i]) continue;

                path.push_back(nums[i]);
                used[i] = true;
                backtrack();
                path.pop_back();
                used[i] = false;
            }

        };

        backtrack();
        return result;
    }
};
