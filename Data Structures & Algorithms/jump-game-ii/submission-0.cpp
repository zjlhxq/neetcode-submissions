class Solution {
public:
    int jump(vector<int>& nums) {
        
        int furthest = 0;
        int currentEnd = 0;
        int jump = 0;
        for( int i=0; i<nums.size() - 1; i++) {
            furthest = max(furthest, i+nums[i]);
            if( i == currentEnd) {
                jump ++;
                currentEnd = furthest;
            }
        }

        return jump;
    }
};
