class Solution {
public:
    int maxArea(vector<int>& heights) {

        int left = 0, right = heights.size() - 1;

        int max_amt = 0;
        while (left < right) {
            int curr_area = 0;
            if (heights[left] <= heights[right]) {
                curr_area = (right - left) * heights[left];
                left ++;
            } else {
                curr_area = (right - left) * heights[right];
                right --;
            }
            max_amt = max(max_amt, curr_area);
        }
        
        return max_amt;
    }
};
