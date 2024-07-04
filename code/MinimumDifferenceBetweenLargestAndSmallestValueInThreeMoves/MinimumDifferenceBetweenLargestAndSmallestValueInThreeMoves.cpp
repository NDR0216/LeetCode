class Solution {
private:
    const int MOVE = 3;

public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();

        if (n <= MOVE) {
            return 0;
        }

        // Note: Assume the implementation preserves the remaining elements
        // order This assumption is unspecified in standard
        partial_sort(nums.begin(), nums.begin() + MOVE + 1, nums.end());
        partial_sort(nums.rbegin(), nums.rbegin() + MOVE + 1, nums.rend(),
                     greater());

        int min_diff = INT_MAX;
        for (int i = 0; i <= MOVE; i++) {
            min_diff = min(min_diff, nums[n - MOVE - 1 + i] - nums[i]);
        }

        return min_diff;
    }
};
