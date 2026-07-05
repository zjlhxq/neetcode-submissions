class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int longest = 0;

        for( auto num : nums) {
            if(!set.contains(num - 1)) {
                int curr_num = num;
                int curr_length = 1;

                while(set.contains(curr_num + 1)) {
                    curr_num ++;
                    curr_length ++;
                }

                longest = max(longest, curr_length);
            }
        }

        return longest; 
    }
};
