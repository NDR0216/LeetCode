class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lowerBound, upperBound;

        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // left == right == lowerBound, 1 element
        lowerBound = left;

        left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // left == right == upperBound, 1 element
        upperBound = left;

        if (lowerBound == upperBound) {
            return {-1, -1};
        }

        return {lowerBound, upperBound - 1};
    }
};
