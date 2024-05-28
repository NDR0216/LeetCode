class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        // if odd, medium'th; if even, medium-1'th + medium'th
        int medium = (m + n) / 2;

        // find medium'th
        int left = max(0, medium - n), right = min(medium, m);
        while (left <= right) {
            // mid1 numbers <= mid1, [0, medium]
            // mid2 numbers <= mid2, [0, medium]
            int mid1 = left + (right - left) / 2;
            int mid2 = medium - mid1;

            int left1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int left2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int right1 = (mid1 == m) ? INT_MAX : nums1[mid1];
            int right2 = (mid2 == n) ? INT_MAX : nums2[mid2];

            if (left1 <= right2 && left2 <= right1) {
                int max_left = max(left1, left2);    // medium-1'th
                int min_right = min(right1, right2); // medium'th

                if ((m + n) % 2 == 1) {
                    return min_right;
                } else {
                    return (max_left + min_right) / 2.0;
                }
            } else if (left2 > right1) { // right1 is too small
                left = mid1 + 1;
            } else {
                right = mid1 - 1;
            }
        }

        return 0.0;
    }
};
