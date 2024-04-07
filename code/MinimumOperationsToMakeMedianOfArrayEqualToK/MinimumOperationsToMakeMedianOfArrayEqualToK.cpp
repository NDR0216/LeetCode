class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int idx = nums.size() / 2;
        long long ops = 0;
        if (nums[idx] > k) {
            while (idx >= 0 && nums[idx] > k) {
                ops += (nums[idx] - k);
                idx--;
            }
        } else if (nums[idx] < k) {
            while (idx < nums.size() && nums[idx] < k) {
                ops += (k - nums[idx]);
                idx++;
            }
        }

        return ops;
    }
};
