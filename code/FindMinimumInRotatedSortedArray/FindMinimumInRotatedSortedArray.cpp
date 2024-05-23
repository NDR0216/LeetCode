class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums[0] <= nums.back()) {
            return nums[0];
        }

        int left = 1, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid - 1]) {
                return nums[mid];
            } else if (nums[mid] > nums[0]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return 0;
    }
};
