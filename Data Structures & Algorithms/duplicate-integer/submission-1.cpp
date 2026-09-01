class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set;
        for(int num : nums) {
            if(nums_set.contains(num)) return true;

            nums_set.insert(num);
        }

        return false;
    }
};