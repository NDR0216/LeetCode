class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int median = nums.size() / 2;

        long long ops = 0;
        if (nums[median] > k) {
            for (int i = median; i >= 0 && nums[i] > k; i--) {
                ops += nums[i] - k;
            }
        } else if (nums[median] < k) {
            for (int i = median; i < nums.size() && nums[i] < k; i++) {
                ops += k - nums[i];
            }
        }

        return ops;
    }
};
