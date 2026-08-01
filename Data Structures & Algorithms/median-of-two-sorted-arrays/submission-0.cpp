class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2;

        int left = 0, right = m;
        double result = 0.0;

        while(left <= right) {
            int i = left + (right - left) / 2;
            int j = half - i;

            int left_a = (i==0) ? INT_MIN : nums1[i-1];
            int right_a = (i == m) ? INT_MAX : nums1[i];
            int left_b = (j==0) ? INT_MIN : nums2[j-1];
            int right_b = (j==n) ? INT_MAX : nums2[j];

            if(left_a > right_b) {
                right = i - 1;
            } else if(left_b > right_a) {
                left = i + 1;
            } else {
                // found the right partition
                if (total % 2 == 1) { // total length is odd
                    result = max(left_a, left_b);
                } else { // even
                    result = (max(left_a, left_b) + min(right_a, right_b)) / 2.0;
                }
                break;
            }
        }

        return result;
    }
};
