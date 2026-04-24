class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // find last j when nums1[i] <= nums2[j]

        int max_dist = 0;

        int j = 0;
        for (int i = 0; i < nums1.size(); i++) {
            while (j + 1 < nums2.size() && nums1[i] <= nums2[j + 1]) {
                j++;
            }

            if (i <= j && nums1[i] <= nums2[j]) {
                max_dist = max(max_dist, j - i);
            }
        }

        return max_dist;
    }
};
