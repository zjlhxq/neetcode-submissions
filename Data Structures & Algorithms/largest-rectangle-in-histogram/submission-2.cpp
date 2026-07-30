class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st; // monotonically increasing

        for(int i=0; i<=n; i++) {
            int current_height = (i==n) ? 0 : heights[i];

            while(!st.empty() && current_height < heights[st.top()]) {
                auto idx = st.top();
                st.pop();

                int width = (st.empty())? i : i - st.top() - 1;

                maxArea = max(maxArea, heights[idx] * width);
            }

            if(i<n) {
                st.push(i);
            }
        }

        return maxArea;
    }
};
